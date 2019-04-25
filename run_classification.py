""" classification demo params check module"""
# !/usr/bin/env python3
# -*- coding: UTF-8 -*-
#
#   =======================================================================
#
# Copyright (C) 2018, Hisilicon Technologies Co., Ltd. All Rights Reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
#   1 Redistributions of source code must retain the above copyright notice,
#     this list of conditions and the following disclaimer.
#
#   2 Redistributions in binary form must reproduce the above copyright notice,
#     this list of conditions and the following disclaimer in the documentation
#     and/or other materials provided with the distribution.
#
#   3 Neither the names of the copyright holders nor the names of the
#   contributors may be used to endorse or promote products derived from this
#   software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#   =======================================================================
#
import argparse
import os
import sys

MODEL_PATH = '${MODEL_PATH}'
GRAPH_TEMPLATE_FILE = 'graph.template'
GRAPH_CONFIG_FILE = 'graph.config'

CPP_EXE = './ascend_cvnetworkverify'
CONCOLE_LIST = ' {} {} {} {} {}'


def get_args():
    """input argument parser function
        -m --model_path: davinci offline model path.
        -w --model_width: width of input images required by model.
        -h --model_height: height of input images required by model.
        -i --input_path: paths and folders of input images.
        -n --top_n: topN classfication results.
        eg:
        python3 classfication_demo.py -m google_net.om \
        -w 224 -h 224 -i ./example.jpg -n 10
    """
    parser = argparse.ArgumentParser(
        conflict_handler='resolve',
        description='eg: python3 classfication_demo.py -m test.om \
        -w 224 -h 224 -i test.jpg -n 10')
    parser.add_argument('-m', '--model_path', required=True,
                        help='davinci offline model path.')
    parser.add_argument('-w', '--model_width', required=True, type=int,
                        help='model input width. range:[16,4096]')
    parser.add_argument('-h', '--model_height', required=True, type=int,
                        help='model input height.range:[16,4096]')
    parser.add_argument('-i', '--input_path', required=True, nargs='*',
                        help='paths of input images. support multipath, using \
                              spaces to distinguish.')
    parser.add_argument('-n', '--top_n', type=int, default=10,
                        help='topN classfication results.')
    return parser.parse_args()


def eprint(*args, **kwargs):
    """print error message to stderr
    """
    print(*args, file=sys.stderr, **kwargs)


def validate_args(args):
    """check console parameters according to restrictions.
    :return: True or False
    """
    check_flag = True
    if not os.path.isfile(args.model_path):
        eprint('[ERROR] offline model does not exist.')
        check_flag = False
    for path in args.input_path:
        if os.path.isdir(path):
            if not os.listdir(path):
                eprint('[ERROR] input image path=%r is empty.' % path)
                check_flag = False
        elif not os.path.isfile(path):
            eprint('[ERROR] input image path=%r does not exist.' % path)
            check_flag = False
    if not 1 <= args.top_n <= 100:
        eprint('[ERROR] topN must be between 1 and 100.')
        check_flag = False
    if not 16 <= args.model_width <= 4096:
        eprint('[ERROR] model width must be between 16 and 4096.')
        check_flag = False
    if not 16 <= args.model_height <= 4096:
        eprint('[ERROR] model height must be between 16 andd 4096.')
        check_flag = False
    return check_flag


def assemble_console_params(args):
    """assemble console params as agreed with cpp program.
    :return: console params string
    """
    image_path = ','.join(args.input_path)
    console_params = CONCOLE_LIST.format(args.model_width, args.model_height,
                                         image_path, "empty",
                                         args.top_n)
    return console_params


def generate_graph(model_path):
    """generate graph config files base on template.
    :param model_path: davinci offline model path.
    """
    if not os.path.isfile(GRAPH_TEMPLATE_FILE):
        eprint('[ERROR] graph template file does not exist.')
        exit()
    with open(GRAPH_TEMPLATE_FILE, 'r') as template_file:
        contents = template_file.read()
        contents = contents.replace(MODEL_PATH, model_path)
    with open(GRAPH_CONFIG_FILE, 'w') as config_file:
        config_file.write(contents)


def main():
    """main function to receive console params then call cpp program.
    """
    args = get_args()
    if validate_args(args):
        generate_graph(os.path.realpath(args.model_path))
        if os.path.exists(CPP_EXE):
            console_params = assemble_console_params(args)
            os.system(CPP_EXE + console_params)
        else:
            eprint('[ERROR] excute file does not exist.')


if __name__ == '__main__':
    main()
