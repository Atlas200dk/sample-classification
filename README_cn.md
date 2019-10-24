中文|[英文](README.md)

# 通用分类网络应用<a name="ZH-CN_TOPIC_0185837622"></a>

本Application支持运行在Atlas 200 DK或者AI加速云服务器上，实现了对常见的分类网络的推理功能并输出前n个推理结果。

## 前提条件<a name="zh-cn_topic_0182554620_section137245294533"></a>

部署此Sample前，需要准备好以下环境：

-   已完成Mind Studio的安装。
-   已完成Atlas 200 DK开发者板与Mind Studio的连接，交叉编译器的安装，SD卡的制作及基本信息的配置等。

## 软件准备<a name="zh-cn_topic_0182554620_section181111827718"></a>

运行此Sample前，需要按照此章节获取源码包，并进行相关的环境配置。

1.  获取源码包。

    将[https://gitee.com/Atlas200DK/sample-classification](https://gitee.com/Atlas200DK/sample-classification)仓中的代码以Mind Studio安装用户下载至Mind Studio所在Ubuntu服务器的任意目录，例如代码存放路径为：_/home/ascend/sample-classification_。

2.  <a name="zh-cn_topic_0182554620_li29641938112018"></a>获取此应用中所需要的原始网络模型。

    参考[表1](#zh-cn_topic_0182554620_table1119094515272)获取此应用中所用到的原始网络模型及其对应的权重文件，并将其存放到Mind Studio所在Ubuntu服务器的任意目录，例如$HOME/ascend/models/classification。

    **表 1**  通用分类网络应用使用模型

    <a name="zh-cn_topic_0182554620_table1119094515272"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0182554620_row677354502719"><th class="cellrowborder" valign="top" width="12.85%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0182554620_p167731845122717"><a name="zh-cn_topic_0182554620_p167731845122717"></a><a name="zh-cn_topic_0182554620_p167731845122717"></a>模型名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.57%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0182554620_p277317459276"><a name="zh-cn_topic_0182554620_p277317459276"></a><a name="zh-cn_topic_0182554620_p277317459276"></a>模型说明</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.58%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0182554620_p9773114512270"><a name="zh-cn_topic_0182554620_p9773114512270"></a><a name="zh-cn_topic_0182554620_p9773114512270"></a>模型下载路径</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0182554620_row3122314144215"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p14407251134314"><a name="zh-cn_topic_0182554620_p14407251134314"></a><a name="zh-cn_topic_0182554620_p14407251134314"></a>alexnet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p116141194720"><a name="zh-cn_topic_0182554620_p116141194720"></a><a name="zh-cn_topic_0182554620_p116141194720"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p86191184712"><a name="zh-cn_topic_0182554620_p86191184712"></a><a name="zh-cn_topic_0182554620_p86191184712"></a>是基于Caffe的AlexNet模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p67311330479"><a name="zh-cn_topic_0182554620_p67311330479"></a><a name="zh-cn_topic_0182554620_p67311330479"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/alexnet" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/alexnet</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row2399521134819"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p3400192113488"><a name="zh-cn_topic_0182554620_p3400192113488"></a><a name="zh-cn_topic_0182554620_p3400192113488"></a>caffenet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p5645133234810"><a name="zh-cn_topic_0182554620_p5645133234810"></a><a name="zh-cn_topic_0182554620_p5645133234810"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p14645153244816"><a name="zh-cn_topic_0182554620_p14645153244816"></a><a name="zh-cn_topic_0182554620_p14645153244816"></a>是基于Caffe的CaffeNet模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p1537844912482"><a name="zh-cn_topic_0182554620_p1537844912482"></a><a name="zh-cn_topic_0182554620_p1537844912482"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/caffenet" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/caffenet</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row3773114518271"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p17738455277"><a name="zh-cn_topic_0182554620_p17738455277"></a><a name="zh-cn_topic_0182554620_p17738455277"></a>densenet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p16773124511270"><a name="zh-cn_topic_0182554620_p16773124511270"></a><a name="zh-cn_topic_0182554620_p16773124511270"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p2773745162718"><a name="zh-cn_topic_0182554620_p2773745162718"></a><a name="zh-cn_topic_0182554620_p2773745162718"></a>是基于Caffe的DenseNet121模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p187731945132715"><a name="zh-cn_topic_0182554620_p187731945132715"></a><a name="zh-cn_topic_0182554620_p187731945132715"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/densenet" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/densenet</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row137731845122710"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p477316457275"><a name="zh-cn_topic_0182554620_p477316457275"></a><a name="zh-cn_topic_0182554620_p477316457275"></a>googlenet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p197731456270"><a name="zh-cn_topic_0182554620_p197731456270"></a><a name="zh-cn_topic_0182554620_p197731456270"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p1877394515274"><a name="zh-cn_topic_0182554620_p1877394515274"></a><a name="zh-cn_topic_0182554620_p1877394515274"></a>是基于Caffe的GoogLeNet模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p197738453275"><a name="zh-cn_topic_0182554620_p197738453275"></a><a name="zh-cn_topic_0182554620_p197738453275"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/googlenet" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/googlenet</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row977374512716"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p1977324512272"><a name="zh-cn_topic_0182554620_p1977324512272"></a><a name="zh-cn_topic_0182554620_p1977324512272"></a><span>inception_v2</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p14773445122712"><a name="zh-cn_topic_0182554620_p14773445122712"></a><a name="zh-cn_topic_0182554620_p14773445122712"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p877311459270"><a name="zh-cn_topic_0182554620_p877311459270"></a><a name="zh-cn_topic_0182554620_p877311459270"></a>是基于Caffe的Inception V2模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p16773145162719"><a name="zh-cn_topic_0182554620_p16773145162719"></a><a name="zh-cn_topic_0182554620_p16773145162719"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/inception_v2" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/inception_v2</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row429165985115"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p1050712711523"><a name="zh-cn_topic_0182554620_p1050712711523"></a><a name="zh-cn_topic_0182554620_p1050712711523"></a><span>inception_v3</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p18641141115218"><a name="zh-cn_topic_0182554620_p18641141115218"></a><a name="zh-cn_topic_0182554620_p18641141115218"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p06411511105213"><a name="zh-cn_topic_0182554620_p06411511105213"></a><a name="zh-cn_topic_0182554620_p06411511105213"></a>是基于Caffe的Inception V3模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p1241971612520"><a name="zh-cn_topic_0182554620_p1241971612520"></a><a name="zh-cn_topic_0182554620_p1241971612520"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/inception_v3" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/inception_v3</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row6482142185210"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p12508168115214"><a name="zh-cn_topic_0182554620_p12508168115214"></a><a name="zh-cn_topic_0182554620_p12508168115214"></a><span>inception_v4</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p8785612105217"><a name="zh-cn_topic_0182554620_p8785612105217"></a><a name="zh-cn_topic_0182554620_p8785612105217"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p47851512105212"><a name="zh-cn_topic_0182554620_p47851512105212"></a><a name="zh-cn_topic_0182554620_p47851512105212"></a>是基于Caffe的Inception V4模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p1028761705212"><a name="zh-cn_topic_0182554620_p1028761705212"></a><a name="zh-cn_topic_0182554620_p1028761705212"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/inception_v4" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/inception_v4</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row77732045152717"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p0773114572715"><a name="zh-cn_topic_0182554620_p0773114572715"></a><a name="zh-cn_topic_0182554620_p0773114572715"></a><span>mobilenet_v1</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p11774645162715"><a name="zh-cn_topic_0182554620_p11774645162715"></a><a name="zh-cn_topic_0182554620_p11774645162715"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p47741455273"><a name="zh-cn_topic_0182554620_p47741455273"></a><a name="zh-cn_topic_0182554620_p47741455273"></a>是基于Caffe的MobileNet V1模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p167741745182714"><a name="zh-cn_topic_0182554620_p167741745182714"></a><a name="zh-cn_topic_0182554620_p167741745182714"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/mobilenet_v1" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/mobilenet_v1</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row12774164515277"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p187741345112718"><a name="zh-cn_topic_0182554620_p187741345112718"></a><a name="zh-cn_topic_0182554620_p187741345112718"></a><span>mobilenet_v2</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p277414519274"><a name="zh-cn_topic_0182554620_p277414519274"></a><a name="zh-cn_topic_0182554620_p277414519274"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p8774174502713"><a name="zh-cn_topic_0182554620_p8774174502713"></a><a name="zh-cn_topic_0182554620_p8774174502713"></a>是基于Caffe的MobileNet V2模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p1677414514274"><a name="zh-cn_topic_0182554620_p1677414514274"></a><a name="zh-cn_topic_0182554620_p1677414514274"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/mobilenet_v2" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/mobilenet_v2</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row1577434516271"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p3774194512713"><a name="zh-cn_topic_0182554620_p3774194512713"></a><a name="zh-cn_topic_0182554620_p3774194512713"></a><span>resnet18</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p7774245122713"><a name="zh-cn_topic_0182554620_p7774245122713"></a><a name="zh-cn_topic_0182554620_p7774245122713"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p577494517271"><a name="zh-cn_topic_0182554620_p577494517271"></a><a name="zh-cn_topic_0182554620_p577494517271"></a>是基于Caffe的ResNet 18模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p16774144510270"><a name="zh-cn_topic_0182554620_p16774144510270"></a><a name="zh-cn_topic_0182554620_p16774144510270"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/resnet18" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/resnet18</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row377414452276"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p10774545142714"><a name="zh-cn_topic_0182554620_p10774545142714"></a><a name="zh-cn_topic_0182554620_p10774545142714"></a><span>resnet50</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p97741245142712"><a name="zh-cn_topic_0182554620_p97741245142712"></a><a name="zh-cn_topic_0182554620_p97741245142712"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p177412456271"><a name="zh-cn_topic_0182554620_p177412456271"></a><a name="zh-cn_topic_0182554620_p177412456271"></a>是基于Caffe的ResNet 50模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p57747459272"><a name="zh-cn_topic_0182554620_p57747459272"></a><a name="zh-cn_topic_0182554620_p57747459272"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/resnet50" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/resnet50</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row377484514279"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p1777454516275"><a name="zh-cn_topic_0182554620_p1777454516275"></a><a name="zh-cn_topic_0182554620_p1777454516275"></a><span>resnet101</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p15774124516274"><a name="zh-cn_topic_0182554620_p15774124516274"></a><a name="zh-cn_topic_0182554620_p15774124516274"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p7774134552720"><a name="zh-cn_topic_0182554620_p7774134552720"></a><a name="zh-cn_topic_0182554620_p7774134552720"></a>是基于Caffe的ResNet 101模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p117741545132710"><a name="zh-cn_topic_0182554620_p117741545132710"></a><a name="zh-cn_topic_0182554620_p117741545132710"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/resnet101" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/resnet101</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row14774154513279"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p1077413452272"><a name="zh-cn_topic_0182554620_p1077413452272"></a><a name="zh-cn_topic_0182554620_p1077413452272"></a><span>resnet15</span>2</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p177434517275"><a name="zh-cn_topic_0182554620_p177434517275"></a><a name="zh-cn_topic_0182554620_p177434517275"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p877515459276"><a name="zh-cn_topic_0182554620_p877515459276"></a><a name="zh-cn_topic_0182554620_p877515459276"></a>是基于Caffe的ResNet 152模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p777514582712"><a name="zh-cn_topic_0182554620_p777514582712"></a><a name="zh-cn_topic_0182554620_p777514582712"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/resnet152" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/resnet152</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row37752450270"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p977544513278"><a name="zh-cn_topic_0182554620_p977544513278"></a><a name="zh-cn_topic_0182554620_p977544513278"></a><span>vgg16</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p1177514522713"><a name="zh-cn_topic_0182554620_p1177514522713"></a><a name="zh-cn_topic_0182554620_p1177514522713"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p10775194582713"><a name="zh-cn_topic_0182554620_p10775194582713"></a><a name="zh-cn_topic_0182554620_p10775194582713"></a>是基于Caffe的VGG16模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p18775124582720"><a name="zh-cn_topic_0182554620_p18775124582720"></a><a name="zh-cn_topic_0182554620_p18775124582720"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/vgg16" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/vgg16</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row2775194518272"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p5775154516272"><a name="zh-cn_topic_0182554620_p5775154516272"></a><a name="zh-cn_topic_0182554620_p5775154516272"></a><span>vgg19</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p0775204532711"><a name="zh-cn_topic_0182554620_p0775204532711"></a><a name="zh-cn_topic_0182554620_p0775204532711"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p1477554519275"><a name="zh-cn_topic_0182554620_p1477554519275"></a><a name="zh-cn_topic_0182554620_p1477554519275"></a>是基于Caffe的VGG19模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p777554542713"><a name="zh-cn_topic_0182554620_p777554542713"></a><a name="zh-cn_topic_0182554620_p777554542713"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/vgg19" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/vgg19</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row17513194404914"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p7513164419495"><a name="zh-cn_topic_0182554620_p7513164419495"></a><a name="zh-cn_topic_0182554620_p7513164419495"></a>squeezenet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p1315111145015"><a name="zh-cn_topic_0182554620_p1315111145015"></a><a name="zh-cn_topic_0182554620_p1315111145015"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p1515131114501"><a name="zh-cn_topic_0182554620_p1515131114501"></a><a name="zh-cn_topic_0182554620_p1515131114501"></a>是基于Caffe的SqueezeNet模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p16265437125015"><a name="zh-cn_topic_0182554620_p16265437125015"></a><a name="zh-cn_topic_0182554620_p16265437125015"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/squeezenet" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/squeezenet</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0182554620_row17757454270"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p17759452279"><a name="zh-cn_topic_0182554620_p17759452279"></a><a name="zh-cn_topic_0182554620_p17759452279"></a><span>dpn98</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p4775545162716"><a name="zh-cn_topic_0182554620_p4775545162716"></a><a name="zh-cn_topic_0182554620_p4775545162716"></a>图片分类推理模型。</p>
    <p id="zh-cn_topic_0182554620_p1577504516278"><a name="zh-cn_topic_0182554620_p1577504516278"></a><a name="zh-cn_topic_0182554620_p1577504516278"></a>是基于Caffe的<span>dpn98</span>模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.58%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p19776154592711"><a name="zh-cn_topic_0182554620_p19776154592711"></a><a name="zh-cn_topic_0182554620_p19776154592711"></a>请参考<a href="https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/dpn98" target="_blank" rel="noopener noreferrer">https://gitee.com/HuaweiAscend/models/tree/master/computer_vision/classification/dpn98</a>目录中README.md下载原始网络模型文件及其对应的权重文件。</p>
    </td>
    </tr>
    </tbody>
    </table>

3.  将原始网络模型转换为Davinci模型。
    1.  在Mind Studio操作界面的顶部菜单栏中选择“Tool \> Convert Model”，进入模型转换界面。
    2.  在弹出的**Convert Model**操作界面中，Model File与Weight File分别选择[2](#zh-cn_topic_0182554620_li29641938112018)中下载的模型文件和权重文件。
        -   **Model Name**填写为[表1](#zh-cn_topic_0182554620_table1119094515272)中对应的**模型名称**。
        -   googlenet、inception\_v2模型中，通用分类网络应用一次处理一张图片，所以转换时需要将Input Shape的N修改为1

            **图 1**  Input Shape配置示例<a name="zh-cn_topic_0182554620_fig95695336322"></a>  
            ![](doc/source/img/Input-Shape配置示例.png "Input-Shape配置示例")


    3.  单击OK开始转换模型。

        模型转换成功后，后缀为.om的Davinci模型存放地址为$HOME/tools/che/model-zoo/my-model/xxx。

4.  以Mind Studio安装用户登录Mind Studio所在Ubuntu服务器，并设置环境变量DDK\_HOME。

    **vim \~/.bashrc**

    执行如下命令在最后一行添加DDK\_HOME及LD\_LIBRARY\_PATH的环境变量。

    **export DDK\_HOME=/home/XXX/tools/che/ddk/ddk**

    **export LD\_LIBRARY\_PATH=$DDK\_HOME/uihost/lib**

    >![](doc/source/img/icon-note.gif) **说明：**   
    >-   XXX为Mind Studio安装用户，/home/XXX/tools为DDK默认安装路径。  
    >-   如果此环境变量已经添加，则此步骤可跳过。  

    输入:wq!保存退出。

    执行如下命令使环境变量生效。

    **source \~/.bashrc**


## 部署<a name="zh-cn_topic_0182554620_section18931344873"></a>

1.  以Mind Studio安装用户进入通用分类网络应用代码所在根目录，如_/home/ascend/sample-classification_。
2.  执行部署脚本，进行工程环境准备，包括公共库的编译与部署、应用的编译与部署等操作。

    **bash deploy.sh  _host\_ip_ _model\_mode_**

    -   _host\_ip_：对于Atlas 200 DK开发者板，即为开发者板的IP地址。对于AI加速云服务器，即为Host的IP地址。
    -   _model\_mode_  代表模型文件的部署方式，默认为internet。
        -   **local**：若Mind Studio所在Ubuntu系统未连接网络，请使用local模式，执行此命令前，需要参考[公共代码库下载](#zh-cn_topic_0182554620_section92241245122511)将依赖的公共代码库ezdvpp下载到“sample-classification/script“目录下。
        -   **internet**：若Mind Studio所在Ubuntu系统已连接网络，请使用internet模式，在线下载依赖代码库ezdvpp。


    命令示例：

    **bash deploy.sh 192.168.1.2 internet**

3.  参考[表1](#zh-cn_topic_0182554620_table1119094515272)将需要使用的已经转换好的Davinci离线模型文件与需要推理的图片上传至Host侧任一属组为HwHiAiUser用户的目录。

    例如将模型文件**alexnet.om**上传到Host侧的“/home/HwHiAiUser/models“目录下。

    图片要求如下：

    -   格式：jpg、png、bmp。
    -   输入图片宽度：16px\~4096px之间的整数。
    -   输入图片高度：16px\~4096px之间的整数。


## 运行<a name="zh-cn_topic_0182554620_section372782554919"></a>

1.  在Mind Studio所在Ubuntu服务器中，以HwHiAiUser用户SSH登录到Host侧。

    **ssh HwHiAiUser@**_host\_ip_

    对于Atlas 200 DK，host\_ip默认为192.168.1.2（USB连接）或者192.168.0.2（NIC连接）。

    对于AI加速云服务器，host\_ip即为当前Mind Studio所在服务器的IP地址。

2.  进入贯通网络的可执行文件所在路径。

    **cd \~/HIAI\_PROJECTS/ascend\_workspace/classification/out**

3.  执行应用程序。

    执行**run\_classification.py**脚本会将推理结果在执行终端直接打印显示。

    命令示例如下所示：

    **python3 run\_classification.py  -m  _\~/models/alexnet.om_  -w  _227_  -h  _227_  -i**

    **_./example.jpg_  -n  _10_**

    -   -m/--model\_path：离线模型存储路径。
    -   -w/model\_width：模型的输入图片宽度，为16\~4096之间的整数，请参考[表1](#zh-cn_topic_0182554620_table1119094515272)在gitee上查看所使用模型文件的Readme，获取模型要求的输入数据的宽和高。
    -   -h/model\_height：模型的输入图片高度，为16\~4096之间的整数，请参考[表1](#zh-cn_topic_0182554620_table1119094515272)在gitee上查看所使用模型文件的Readme，获取模型要求的输入数据的宽和高。
    -   -i/input\_path：输入图片的路径，可以是目录，表示当前目录下的所有图片都作为输入（可以指定多个输入）。
    -   -n/top\_n：输出前n个推理结果。

    其他详细参数请执行**python3 run\_classification.py --help**命令参见帮助信息。


## 公共代码库下载<a name="zh-cn_topic_0182554620_section92241245122511"></a>

将依赖的软件库下载到“sample-classification/script“目录下。

**表 2**  依赖代码库下载

<a name="zh-cn_topic_0182554620_table193598342368"></a>
<table><thead align="left"><tr id="zh-cn_topic_0182554620_row1335913343368"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0182554620_p235913463620"><a name="zh-cn_topic_0182554620_p235913463620"></a><a name="zh-cn_topic_0182554620_p235913463620"></a>模块名称</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0182554620_p15359143483614"><a name="zh-cn_topic_0182554620_p15359143483614"></a><a name="zh-cn_topic_0182554620_p15359143483614"></a>模块描述</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0182554620_p8359734133612"><a name="zh-cn_topic_0182554620_p8359734133612"></a><a name="zh-cn_topic_0182554620_p8359734133612"></a>下载地址</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0182554620_row436033423616"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0182554620_p63603349365"><a name="zh-cn_topic_0182554620_p63603349365"></a><a name="zh-cn_topic_0182554620_p63603349365"></a>EZDVPP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0182554620_p1360434113620"><a name="zh-cn_topic_0182554620_p1360434113620"></a><a name="zh-cn_topic_0182554620_p1360434113620"></a>对DVPP接口进行了封装，提供对图片/视频的处理能力。</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0182554620_p63606348367"><a name="zh-cn_topic_0182554620_p63606348367"></a><a name="zh-cn_topic_0182554620_p63606348367"></a><a href="https://gitee.com/Atlas200DK/sdk-ezdvpp" target="_blank" rel="noopener noreferrer">https://gitee.com/Atlas200DK/sdk-ezdvpp</a></p>
<p id="zh-cn_topic_0182554620_p5360133420366"><a name="zh-cn_topic_0182554620_p5360133420366"></a><a name="zh-cn_topic_0182554620_p5360133420366"></a>下载后请保持文件夹名称为ezdvpp。</p>
</td>
</tr>
</tbody>
</table>

