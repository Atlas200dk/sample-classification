/**
 * ============================================================================
 *
 * Copyright (C) 2018, Hisilicon Technologies Co., Ltd. All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   1 Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   2 Redistributions in binary form must reproduce the above copyright notice,
 *     this list of conditions and the following disclaimer in the documentation
 *     and/or other materials provided with the distribution.
 *
 *   3 Neither the names of the copyright holders nor the names of the
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 * ============================================================================
 */

#include "general_post.h"

#include <unistd.h>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>

#include "hiaiengine/log.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgcodecs/legacy/constants_c.h"
#include "tool_api.h"

using hiai::Engine;
using namespace std;

namespace {
// callback port (engine port begin with 0)
const uint32_t kSendDataPort = 0;

// sleep interval when queue full (unit:microseconds)
const __useconds_t kSleepInterval = 200000;

// topN result separator
// such as "idx1:value1,idx2:value2,idx3:value3"
const string kTopNIndexSeparator = ":";
const string kTopNValueSeparator = ",";
}
// namespace

// register custom data type
HIAI_REGISTER_DATA_TYPE("EngineTrans", EngineTrans);

HIAI_StatusT GeneralPost::Init(
    const hiai::AIConfig &config,
    const vector<hiai::AIModelDescription> &model_desc) {
  // do noting
  return HIAI_OK;
}

bool GeneralPost::SendSentinel() {
  // can not discard when queue full
  HIAI_StatusT hiai_ret = HIAI_OK;
  shared_ptr<string> sentinel_msg(new (nothrow) string);
  do {
    hiai_ret = SendData(kSendDataPort, "string",
                        static_pointer_cast<void>(sentinel_msg));
    // when queue full, sleep
    if (hiai_ret == HIAI_QUEUE_FULL) {
      HIAI_ENGINE_LOG("queue full, sleep 200ms");
      usleep(kSleepInterval);
    }
  } while (hiai_ret == HIAI_QUEUE_FULL);

  // send failed
  if (hiai_ret != HIAI_OK) {
    HIAI_ENGINE_LOG(HIAI_ENGINE_RUN_ARGS_NOT_RIGHT,
                    "call SendData failed, err_code=%d", hiai_ret);
    return false;
  }
  return true;
}

string GenerateTopNStr(int32_t top_n, const vector<float> &varr) {
  // if topN max than size, only return size count
  if (top_n > varr.size()) {
    top_n = varr.size();
  }

  // generate index vector from 0 ~ size -1
  vector<size_t> idx(varr.size());
  iota(idx.begin(), idx.end(), 0);
  // sort by original data
  sort(idx.begin(), idx.end(),
       [&varr](size_t i1, size_t i2) {return varr[i1] > varr[i2];});

  // generate result
  stringstream top_stream;
  for (int32_t i = 0; i < top_n; i++) {
    top_stream << idx[i] << kTopNIndexSeparator;
    top_stream << to_string(varr[idx[i]]) << kTopNValueSeparator;
  }

  // return string(need sub last character)
  string result_str = "";
  top_stream >> result_str;
  result_str.pop_back();
  return result_str;
}

HIAI_StatusT GeneralPost::ClassficationPostProcess(
    const std::shared_ptr<EngineTrans> &result) {
  string file_path = result->image_info.path;
  // check vector
  if (result->inference_res.empty()) {
    ERROR_LOG("Failed to deal file=%s. Reason: inference result empty.",
              file_path.c_str());
    return HIAI_ERROR;
  }

  // only need to get first one
  Output out = result->inference_res[0];
  int32_t size = out.size / sizeof(float);
  if (size <= 0) {
    ERROR_LOG("Failed to deal file=%s. Reason: inference result size=%d error.",
              file_path.c_str(), size);
    return HIAI_ERROR;
  }

  // transform results
  float *res = new (nothrow) float[size];
  if (res == nullptr) {
    ERROR_LOG("Failed to deal file=%s. Reason: new float array failed.",
              file_path.c_str());
    return HIAI_ERROR;
  }
  errno_t mem_ret = memcpy_s(res, sizeof(float) * size, out.data.get(),
                             out.size);
  if (mem_ret != EOK) {
    delete[] res;
    ERROR_LOG("Failed to deal file=%s. Reason: call memcpy_s failed.",
              file_path.c_str());
    return HIAI_ERROR;
  }

  // get topN
  int32_t top_n = result->console_params.output_nums;
  vector<float> varr(res, res + size);
  string top_n_str = GenerateTopNStr(top_n, varr);
  delete[] res;
  INFO_LOG("Success to deal file=%s.", file_path.c_str());
  INFO_LOG("Top index and confidence:%s", top_n_str.c_str())
  return HIAI_OK;
}

HIAI_IMPL_ENGINE_PROCESS("general_post", GeneralPost, INPUT_SIZE) {
  HIAI_StatusT ret = HIAI_OK;

  // check arg0
  if (arg0 == nullptr) {
    ERROR_LOG("Failed to deal file=nothing. Reason: arg0 is empty.");
    return HIAI_ERROR;
  }

  // just send to callback function when finished
  shared_ptr<EngineTrans> result = static_pointer_cast<EngineTrans>(arg0);
  if (result->is_finished) {
    if (SendSentinel()) {
      return HIAI_OK;
    }
    ERROR_LOG("Failed to send finish data. Reason: SendData failed.");
    ERROR_LOG("Please stop this process manually.");
    return HIAI_ERROR;
  }

  // inference failed
  if (result->err_msg.error) {
    ERROR_LOG("%s", result->err_msg.err_msg.c_str());
    return HIAI_ERROR;
  }

  // arrange result
  return ClassficationPostProcess(result);
}
