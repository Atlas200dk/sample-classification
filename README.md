# Image Classification<a name="EN-US_TOPIC_0167609394"></a>

The classification application runs on the Atlas 200 DK or the AI acceleration cloud server and implements the inference function by using a common classification network, and the first  _n_  inference results are output.

## Prerequisites<a name="en-us_topic_0182554620_section137245294533"></a>

Before using an open source application, ensure that:

-   Mind Studio  has been installed.
-   The Atlas 200 DK developer board has been connected to  Mind Studio, the cross compiler has been installed, the SD card has been prepared, and basic information has been configured.

## Software Preparation<a name="en-us_topic_0182554620_section181111827718"></a>

Before running the application, obtain the source code package and configure the environment as follows.

1.  Obtain the source code package.

    Download all the code in the sample-classification repository at  [https://github.com/Ascend/sample-classification](https://github.com/Ascend/sample-classification)  to any directory on Ubuntu Server where  Mind Studio  is located as the  Mind Studio  installation user, for example,  _/home/ascend/sample-classification_.

2.  <a name="en-us_topic_0182554620_li29641938112018"></a>Obtain the source network model required by the application.

    Obtain the source network model and its weight file used in the application by referring to  [Table 1](#en-us_topic_0182554620_table1119094515272), and save them to any directory on the Ubuntu server where  Mind Studio  is located (for example,  **$HOME/ascend/models/classification**).

    **Table  1**  Models used in the general  **classification**  network application

    <a name="en-us_topic_0182554620_table1119094515272"></a>
    <table><thead align="left"><tr id="en-us_topic_0182554620_row677354502719"><th class="cellrowborder" valign="top" width="12.85%" id="mcps1.2.4.1.1"><p id="en-us_topic_0182554620_p167731845122717"><a name="en-us_topic_0182554620_p167731845122717"></a><a name="en-us_topic_0182554620_p167731845122717"></a>Model Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.7%" id="mcps1.2.4.1.2"><p id="en-us_topic_0182554620_p277317459276"><a name="en-us_topic_0182554620_p277317459276"></a><a name="en-us_topic_0182554620_p277317459276"></a>Model Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="74.45%" id="mcps1.2.4.1.3"><p id="en-us_topic_0182554620_p9773114512270"><a name="en-us_topic_0182554620_p9773114512270"></a><a name="en-us_topic_0182554620_p9773114512270"></a>Model Download Path</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0182554620_row9456219205718"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p14407251134314"><a name="en-us_topic_0182554620_p14407251134314"></a><a name="en-us_topic_0182554620_p14407251134314"></a>alexnet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p19207543195714"><a name="en-us_topic_0182554620_p19207543195714"></a><a name="en-us_topic_0182554620_p19207543195714"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p20207114365710"><a name="en-us_topic_0182554620_p20207114365710"></a><a name="en-us_topic_0182554620_p20207114365710"></a>It is a AlexNet model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p67311330479"><a name="en-us_topic_0182554620_p67311330479"></a><a name="en-us_topic_0182554620_p67311330479"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b1195715819"><a name="en-us_topic_0182554620_b1195715819"></a><a name="en-us_topic_0182554620_b1195715819"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/alexnet" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/alexnet</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row982061515578"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p3400192113488"><a name="en-us_topic_0182554620_p3400192113488"></a><a name="en-us_topic_0182554620_p3400192113488"></a>caffenet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p19842133085816"><a name="en-us_topic_0182554620_p19842133085816"></a><a name="en-us_topic_0182554620_p19842133085816"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p08421530135810"><a name="en-us_topic_0182554620_p08421530135810"></a><a name="en-us_topic_0182554620_p08421530135810"></a>It is a CaffeNet model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p1537844912482"><a name="en-us_topic_0182554620_p1537844912482"></a><a name="en-us_topic_0182554620_p1537844912482"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b67963501585"><a name="en-us_topic_0182554620_b67963501585"></a><a name="en-us_topic_0182554620_b67963501585"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/caffenet" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/caffenet</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row3773114518271"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p17738455277"><a name="en-us_topic_0182554620_p17738455277"></a><a name="en-us_topic_0182554620_p17738455277"></a>densenet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p16773124511270"><a name="en-us_topic_0182554620_p16773124511270"></a><a name="en-us_topic_0182554620_p16773124511270"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p2773745162718"><a name="en-us_topic_0182554620_p2773745162718"></a><a name="en-us_topic_0182554620_p2773745162718"></a>It is a DenseNet121 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p187731945132715"><a name="en-us_topic_0182554620_p187731945132715"></a><a name="en-us_topic_0182554620_p187731945132715"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b133652512126"><a name="en-us_topic_0182554620_b133652512126"></a><a name="en-us_topic_0182554620_b133652512126"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/densenet" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/densenet</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row137731845122710"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p477316457275"><a name="en-us_topic_0182554620_p477316457275"></a><a name="en-us_topic_0182554620_p477316457275"></a>googlenet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p197731456270"><a name="en-us_topic_0182554620_p197731456270"></a><a name="en-us_topic_0182554620_p197731456270"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p1877394515274"><a name="en-us_topic_0182554620_p1877394515274"></a><a name="en-us_topic_0182554620_p1877394515274"></a>It is a GoogLeNet model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p197738453275"><a name="en-us_topic_0182554620_p197738453275"></a><a name="en-us_topic_0182554620_p197738453275"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b163671451151214"><a name="en-us_topic_0182554620_b163671451151214"></a><a name="en-us_topic_0182554620_b163671451151214"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/googlenet" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/googlenet</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row977374512716"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p1977324512272"><a name="en-us_topic_0182554620_p1977324512272"></a><a name="en-us_topic_0182554620_p1977324512272"></a><span>inception_v2</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p14773445122712"><a name="en-us_topic_0182554620_p14773445122712"></a><a name="en-us_topic_0182554620_p14773445122712"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p877311459270"><a name="en-us_topic_0182554620_p877311459270"></a><a name="en-us_topic_0182554620_p877311459270"></a>It is an Inception V2 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p16773145162719"><a name="en-us_topic_0182554620_p16773145162719"></a><a name="en-us_topic_0182554620_p16773145162719"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b237065110124"><a name="en-us_topic_0182554620_b237065110124"></a><a name="en-us_topic_0182554620_b237065110124"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/inception_v2" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/inception_v2</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row68081614598"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p594310247598"><a name="en-us_topic_0182554620_p594310247598"></a><a name="en-us_topic_0182554620_p594310247598"></a><span>inception_v3</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p13943202485919"><a name="en-us_topic_0182554620_p13943202485919"></a><a name="en-us_topic_0182554620_p13943202485919"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p39448249596"><a name="en-us_topic_0182554620_p39448249596"></a><a name="en-us_topic_0182554620_p39448249596"></a>It is an Inception V3 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p1794402495919"><a name="en-us_topic_0182554620_p1794402495919"></a><a name="en-us_topic_0182554620_p1794402495919"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b8944142410596"><a name="en-us_topic_0182554620_b8944142410596"></a><a name="en-us_topic_0182554620_b8944142410596"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/inception_v3" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/inception_v3</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row14605131925913"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p9720112614590"><a name="en-us_topic_0182554620_p9720112614590"></a><a name="en-us_topic_0182554620_p9720112614590"></a><span>inception_v4</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p672019267599"><a name="en-us_topic_0182554620_p672019267599"></a><a name="en-us_topic_0182554620_p672019267599"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p2720202614599"><a name="en-us_topic_0182554620_p2720202614599"></a><a name="en-us_topic_0182554620_p2720202614599"></a>It is an Inception V4 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p87209262595"><a name="en-us_topic_0182554620_p87209262595"></a><a name="en-us_topic_0182554620_p87209262595"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b8720202695912"><a name="en-us_topic_0182554620_b8720202695912"></a><a name="en-us_topic_0182554620_b8720202695912"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/inception_v4" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/inception_v4</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row77732045152717"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p0773114572715"><a name="en-us_topic_0182554620_p0773114572715"></a><a name="en-us_topic_0182554620_p0773114572715"></a><span>mobilenet_v1</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p11774645162715"><a name="en-us_topic_0182554620_p11774645162715"></a><a name="en-us_topic_0182554620_p11774645162715"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p47741455273"><a name="en-us_topic_0182554620_p47741455273"></a><a name="en-us_topic_0182554620_p47741455273"></a>It is a MobileNet V1 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p167741745182714"><a name="en-us_topic_0182554620_p167741745182714"></a><a name="en-us_topic_0182554620_p167741745182714"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b11372951161212"><a name="en-us_topic_0182554620_b11372951161212"></a><a name="en-us_topic_0182554620_b11372951161212"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/mobilenet_v1" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/mobilenet_v1</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row12774164515277"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p187741345112718"><a name="en-us_topic_0182554620_p187741345112718"></a><a name="en-us_topic_0182554620_p187741345112718"></a><span>mobilenet_v2</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p277414519274"><a name="en-us_topic_0182554620_p277414519274"></a><a name="en-us_topic_0182554620_p277414519274"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p1517617411496"><a name="en-us_topic_0182554620_p1517617411496"></a><a name="en-us_topic_0182554620_p1517617411496"></a>It is a MobileNet V2 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p1677414514274"><a name="en-us_topic_0182554620_p1677414514274"></a><a name="en-us_topic_0182554620_p1677414514274"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b113751751171215"><a name="en-us_topic_0182554620_b113751751171215"></a><a name="en-us_topic_0182554620_b113751751171215"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/mobilenet_v2" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/mobilenet_v2</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row1577434516271"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p3774194512713"><a name="en-us_topic_0182554620_p3774194512713"></a><a name="en-us_topic_0182554620_p3774194512713"></a><span>resnet18</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p7774245122713"><a name="en-us_topic_0182554620_p7774245122713"></a><a name="en-us_topic_0182554620_p7774245122713"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p2424124816497"><a name="en-us_topic_0182554620_p2424124816497"></a><a name="en-us_topic_0182554620_p2424124816497"></a>It is a ResNet 18 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p16774144510270"><a name="en-us_topic_0182554620_p16774144510270"></a><a name="en-us_topic_0182554620_p16774144510270"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b9376185110123"><a name="en-us_topic_0182554620_b9376185110123"></a><a name="en-us_topic_0182554620_b9376185110123"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/resnet18" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/resnet18</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row377414452276"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p10774545142714"><a name="en-us_topic_0182554620_p10774545142714"></a><a name="en-us_topic_0182554620_p10774545142714"></a><span>resnet50</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p97741245142712"><a name="en-us_topic_0182554620_p97741245142712"></a><a name="en-us_topic_0182554620_p97741245142712"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p12971165614498"><a name="en-us_topic_0182554620_p12971165614498"></a><a name="en-us_topic_0182554620_p12971165614498"></a>It is a ResNet 50 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p57747459272"><a name="en-us_topic_0182554620_p57747459272"></a><a name="en-us_topic_0182554620_p57747459272"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b837835111214"><a name="en-us_topic_0182554620_b837835111214"></a><a name="en-us_topic_0182554620_b837835111214"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/resnet50" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/resnet50</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row377484514279"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p1777454516275"><a name="en-us_topic_0182554620_p1777454516275"></a><a name="en-us_topic_0182554620_p1777454516275"></a><span>resnet101</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p15774124516274"><a name="en-us_topic_0182554620_p15774124516274"></a><a name="en-us_topic_0182554620_p15774124516274"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p6234817509"><a name="en-us_topic_0182554620_p6234817509"></a><a name="en-us_topic_0182554620_p6234817509"></a>It is a ResNet 101 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p117741545132710"><a name="en-us_topic_0182554620_p117741545132710"></a><a name="en-us_topic_0182554620_p117741545132710"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b163801051121213"><a name="en-us_topic_0182554620_b163801051121213"></a><a name="en-us_topic_0182554620_b163801051121213"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/resnet101" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/resnet101</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row14774154513279"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p1077413452272"><a name="en-us_topic_0182554620_p1077413452272"></a><a name="en-us_topic_0182554620_p1077413452272"></a><span>resnet152</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p177434517275"><a name="en-us_topic_0182554620_p177434517275"></a><a name="en-us_topic_0182554620_p177434517275"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p877515459276"><a name="en-us_topic_0182554620_p877515459276"></a><a name="en-us_topic_0182554620_p877515459276"></a>It is a ResNet 152 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p777514582712"><a name="en-us_topic_0182554620_p777514582712"></a><a name="en-us_topic_0182554620_p777514582712"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b10381751171220"><a name="en-us_topic_0182554620_b10381751171220"></a><a name="en-us_topic_0182554620_b10381751171220"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/resnet152" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/resnet152</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row37752450270"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p977544513278"><a name="en-us_topic_0182554620_p977544513278"></a><a name="en-us_topic_0182554620_p977544513278"></a><span>vgg16</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p1177514522713"><a name="en-us_topic_0182554620_p1177514522713"></a><a name="en-us_topic_0182554620_p1177514522713"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p10775194582713"><a name="en-us_topic_0182554620_p10775194582713"></a><a name="en-us_topic_0182554620_p10775194582713"></a>It is a VGG16 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p18775124582720"><a name="en-us_topic_0182554620_p18775124582720"></a><a name="en-us_topic_0182554620_p18775124582720"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b113831451181215"><a name="en-us_topic_0182554620_b113831451181215"></a><a name="en-us_topic_0182554620_b113831451181215"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/vgg16" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/vgg16</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row2775194518272"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p5775154516272"><a name="en-us_topic_0182554620_p5775154516272"></a><a name="en-us_topic_0182554620_p5775154516272"></a><span>vgg19</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p0775204532711"><a name="en-us_topic_0182554620_p0775204532711"></a><a name="en-us_topic_0182554620_p0775204532711"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p104610811513"><a name="en-us_topic_0182554620_p104610811513"></a><a name="en-us_topic_0182554620_p104610811513"></a>It is a VGG19 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p777554542713"><a name="en-us_topic_0182554620_p777554542713"></a><a name="en-us_topic_0182554620_p777554542713"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b19384451171215"><a name="en-us_topic_0182554620_b19384451171215"></a><a name="en-us_topic_0182554620_b19384451171215"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/vgg19" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/vgg19</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row55807131308"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p7513164419495"><a name="en-us_topic_0182554620_p7513164419495"></a><a name="en-us_topic_0182554620_p7513164419495"></a>squeezenet</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p33731240809"><a name="en-us_topic_0182554620_p33731240809"></a><a name="en-us_topic_0182554620_p33731240809"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p03731401304"><a name="en-us_topic_0182554620_p03731401304"></a><a name="en-us_topic_0182554620_p03731401304"></a>It is a SqueezeNet model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p16265437125015"><a name="en-us_topic_0182554620_p16265437125015"></a><a name="en-us_topic_0182554620_p16265437125015"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b17968122318"><a name="en-us_topic_0182554620_b17968122318"></a><a name="en-us_topic_0182554620_b17968122318"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/squeezenet" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/squeezenet</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0182554620_row17757454270"><td class="cellrowborder" valign="top" width="12.85%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p17759452279"><a name="en-us_topic_0182554620_p17759452279"></a><a name="en-us_topic_0182554620_p17759452279"></a><span>dpn98</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="12.7%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p4775545162716"><a name="en-us_topic_0182554620_p4775545162716"></a><a name="en-us_topic_0182554620_p4775545162716"></a>Image&nbsp;classification&nbsp;inference&nbsp;model.</p>
    <p id="en-us_topic_0182554620_p1577504516278"><a name="en-us_topic_0182554620_p1577504516278"></a><a name="en-us_topic_0182554620_p1577504516278"></a>It is a DPN-98 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="74.45%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p19776154592711"><a name="en-us_topic_0182554620_p19776154592711"></a><a name="en-us_topic_0182554620_p19776154592711"></a>Download the source network model file and its weight file by referring to<strong id="en-us_topic_0182554620_b138619511120"><a name="en-us_topic_0182554620_b138619511120"></a><a name="en-us_topic_0182554620_b138619511120"></a> README.md</strong> in <a href="https://github.com/Ascend/models/tree/master/computer_vision/classification/dpn98" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/tree/master/computer_vision/classification/dpn98</a>.</p>
    </td>
    </tr>
    </tbody>
    </table>

3.  Convert the source network model to a Da Vinci model.
    1.  Choose  **Tool \> Convert Model**  from the main menu of  Mind Studio. The  **Convert Model**  page is displayed.
    2.  On the  **Convert Model**  page, set  **Model File** and  **Weight File**  to the model file and weight file downloaded in  [2](#en-us_topic_0182554620_li29641938112018), respectively.
        -   Set  **Model Name**  to the model name in  [Table 1](#en-us_topic_0182554620_table1119094515272).
        -   For the GoogleNet and Inception\_v2 models, a general classification network application processes one image at a time. Therefore, the value of  **N**  in  **Input Shape**  must be set to  **1**  during conversion.

            **Figure  1**  Input Shape configuration reference<a name="en-us_topic_0182554620_fig95695336322"></a>  
            ![](doc/source/img/input-shape-configuration-reference.png "input-shape-configuration-reference")


    3.  Click  **OK**  to start model conversion.

        After successful conversion, a .om Da Vinci model is generated in the  **$HOME/tools/che/model-zoo/my-model/xxx**  directory.

4.  Log in to Ubuntu Server where  Mind Studio  is located as the  Mind Studio  installation user and set the environment variable  **DDK\_HOME**.

    **vim \~/.bashrc**

    Run the following commands to add the environment variables  **DDK\_HOME**  and  **LD\_LIBRARY\_PATH**  to the last line:

    **export DDK\_HOME=/home/XXX/tools/che/ddk/ddk**

    **export LD\_LIBRARY\_PATH=$DDK\_HOME/uihost/lib**

    >![](doc/source/img/icon-note.gif) **NOTE:**   
    >-   **XXX**  indicates the  Mind Studio  installation user, and  **/home/XXX/tools**  indicates the default installation path of the DDK.  
    >-   If the environment variables have been added, skip this step.  

    Enter  **:wq!**  to save and exit.

    Run the following command for the environment variable to take effect:

    **source \~/.bashrc**


## Deployment<a name="en-us_topic_0182554620_section18931344873"></a>

1.  Access the root directory where the classification application code is located as the  Mind Studio  installation user, for example,  _**/home/ascend/sample-classification**_.
2.  Run the deployment script to prepare the project environment, including compiling and deploying the ascenddk public library and application.

    **bash deploy.sh  _host\_ip_** _model_mode_

    -   _host\_ip_: For the Atlas 200 DK developer board, this parameter indicates the IP address of the developer board.For the AI acceleration cloud server, this parameter indicates the IP address of the host.
    -   _model\_mode_  indicates the deployment mode of the model file. The default setting is  **internet**.
        -   **local**: If the Ubuntu system where  Mind Studio  is located is not connected to the network, use the local mode. In this case, download the dependent common code library ezdvpp to the  **sample-classification/script**  directory by referring to the  [Downloading Dependent Code Library](#en-us_topic_0182554620_section92241245122511).
        -   **internet**: Indicates the online deployment mode. If the Ubuntu system where  Mind Studio  is located is connected to the network, use the Internet mode. In this case, download the dependent code library ezdvpp online.


    Example command:

    **bash deploy.sh 192.168.1.2 internet**

3.  Upload the generated Da Vinci offline model and images to be inferred to the directory of the  **HwHiAiUser**  user on the host. For details, see  [Table 1](#en-us_topic_0182554620_table1119094515272).

    For example, upload the model file  **alexnet.om**  to the  **/home/HwHiAiUser/models**  directory on the host.

    The image requirements are as follows:

    -   Format: JPG, PNG, and BMP.
    -   Width of the input image: the value is an integer ranging from 16px to 4096px.
    -   Height of the input image: the value is an integer ranging from 16px to 4096px.


## Running<a name="en-us_topic_0182554620_section372782554919"></a>

1.  Log in to the Host as the  **HwHiAiUser**  user in SSH mode on Ubuntu Server where  Mind Studio  is located.

    **ssh HwHiAiUser@**_host\_ip_

    For the Atlas 200 DK, the default value of  _**host\_ip**_  is  **192.168.1.2**  \(USB connection mode\) or  **192.168.0.2**  \(NIC connection mode\).

    For the AI acceleration cloud server,  _**host\_ip**_  indicates the IP address of the server where  Mind Studio  is located.

2.  Go to the path of the executable file of classification application.

    **cd \~/HIAI\_PROJECTS/ascend\_workspace/classification/out**

3.  Run the application.

    Run the  **run\_classification.py**  script to print the inference result on the execution terminal.

    Example command:

    **python3 run\_classification.py -m  _\~/models/alexnet.om_  -w  _224_  -h  _224_  -i**

    **_./example.jpg_  -n  _10_**

    -   **-m/--model\_path**: path for storing offline models
    -   **-w/model\_width**: width of the input image of a model. The value is an integer ranging from 16px to 4096px. Obtain the input width and height required by each model by referring to the readme file of each model file on GitHub. For details, see  [Table 1](#en-us_topic_0182554620_table1119094515272).
    -   **-h/model\_height**: height of the input image of a model. The value is an integer ranging from 16px to 4096px. Obtain the input width and height required by each model by referring to the readme file of each model file on GitHub. For details, see  [Table 1](#en-us_topic_0182554620_table1119094515272).
    -   **-i/input\_path**: path of the input image. It can be a directory, indicating that all images in the current directory are used as input (Multiple inputs can be specified).
    -   **-n/top\_n**: the first  _n_  inference results that are output

    For other parameters, run the  **python3 run\_classification.py --help**  command. For details, see the help information.


## Downloading Dependent Code Library<a name="en-us_topic_0182554620_section92241245122511"></a>

Download the dependent software libraries to the  **sample-classification/script**  directory.

**Table  2**  Download the dependent software library

<a name="en-us_topic_0182554620_table1140133816250"></a>
<table><thead align="left"><tr id="en-us_topic_0182554620_row941116172360"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="en-us_topic_0182554620_p104111717153616"><a name="en-us_topic_0182554620_p104111717153616"></a><a name="en-us_topic_0182554620_p104111717153616"></a>Module Name</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="en-us_topic_0182554620_p24111617103612"><a name="en-us_topic_0182554620_p24111617103612"></a><a name="en-us_topic_0182554620_p24111617103612"></a>Module Description</p>
</th>
<th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="en-us_topic_0182554620_p13411191711362"><a name="en-us_topic_0182554620_p13411191711362"></a><a name="en-us_topic_0182554620_p13411191711362"></a>Download Address</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0182554620_row9411517143617"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0182554620_p141171733611"><a name="en-us_topic_0182554620_p141171733611"></a><a name="en-us_topic_0182554620_p141171733611"></a>EZDVPP</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0182554620_p12411101713365"><a name="en-us_topic_0182554620_p12411101713365"></a><a name="en-us_topic_0182554620_p12411101713365"></a>Encapsulates the DVPP interface and provides image and video processing capabilities, such as color gamut conversion and image / video conversion</p>
</td>
<td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0182554620_p194114175364"><a name="en-us_topic_0182554620_p194114175364"></a><a name="en-us_topic_0182554620_p194114175364"></a><a href="https://github.com/Ascend/sdk-ezdvpp" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/sdk-ezdvpp</a></p>
<p id="en-us_topic_0182554620_p8411517153611"><a name="en-us_topic_0182554620_p8411517153611"></a><a name="en-us_topic_0182554620_p8411517153611"></a>After the download, keep the folder name <span class="filepath" id="en-us_topic_0182554620_filepath16411117183612"><a name="en-us_topic_0182554620_filepath16411117183612"></a><a name="en-us_topic_0182554620_filepath16411117183612"></a><b>ezdvpp</b></span>.</p>
</td>
</tr>
</tbody>
</table>

