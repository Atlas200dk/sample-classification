中文|[英文](README.md)
 
本Application支持运行在Atlas 200 DK或者AI加速云服务器上，实现了对常见的分类网络的推理功能并输出前n个推理结果。

## 前提条件<a name="zh-cn_topic_0167414508_section137245294533"></a>

部署此Sample前，需要准备好以下环境：

-   已完成MindSpore Studio的安装，详细请参考[MindSpore Studio安装指南](https://www.huawei.com/minisite/ascend/cn/filedetail_1.html)。
-   已完成Atlas 200 DK开发者板与MindSpore Studio的连接，交叉编译器的安装，SD卡的制作及基本信息的配置等，详细请参考[Atlas 200 DK使用指南](https://www.huawei.com/minisite/ascend/cn/filedetail_2.html)。

## 软件准备<a name="zh-cn_topic_0167414508_section181111827718"></a>

运行此Sample前，需要按照此章节获取源码包，并进行相关的环境配置。

1.  获取源码包。

    将[https://github.com/Ascend/sample-classification](https://github.com/Ascend/sample-classification)仓中的代码以MindSpore Studio安装用户下载至MindSpore Studio所在Ubuntu服务器的任意目录，例如代码存放路径为：_/home/ascend/sample-classification_。

2.  以MindSpore Studio安装用户登录MindSpore Studio所在Ubuntu服务器，并设置环境变量DDK\_HOME。

    **vim \~/.bashrc**

    执行如下命令在最后一行添加DDK\_HOME及LD\_LIBRARY\_PATH的环境变量。

    **export DDK\_HOME=/home/XXX/tools/che/ddk/ddk**

    **export LD\_LIBRARY\_PATH=$DDK\_HOME/uihost/lib**

    >![](doc/source/img/icon-note.gif) **说明：**   
    >-   XXX为MindSpore Studio安装用户，/home/XXX/tools为DDK默认安装路径。  
    >-   如果此环境变量已经添加，则此步骤可跳过。  

    输入:wq!保存退出。

    执行如下命令使环境变量生效。

    **source \~/.bashrc**


## 部署<a name="zh-cn_topic_0167414508_section18931344873"></a>

1.  以MindSpore Studio安装用户进入通用分类网络应用代码所在根目录，如 _/home/ascend/sample-classification_。
2.  执行部署脚本，进行工程环境准备，包括公共库的编译与部署、应用的编译与部署等操作。

    bash deploy.sh  _host\_ip_ _model\_mode_

    -   _host\_ip_：对于Atlas 200 DK开发者板，即为开发者板的IP地址。对于AI加速云服务器，即为Host的IP地址。
    -   local：若MindSpore Studio所在Ubuntu系统未连接网络，请使用local模式，执行此命令前，需要参考[网络模型及公共代码库下载](#zh-cn_topic_0167414508_section92241245122511)将依赖的公共代码库ezdvpp下载到“sample-classification/script“目录下。
    -   internet：若MindSpore Studio所在Ubuntu系统已连接网络，请使用internet模式，在线下载依赖代码库ezdvpp。

    命令示例：

    **bash deploy.sh 192.168.1.2 internet**

3.  参考[网络模型及公共代码库下载](#zh-cn_topic_0167414508_section92241245122511)将需要使用的离线模型文件与需要推理的图片上传至Host侧任一属组为HwHiAiUser用户的目录。

    例如将模型文件**alexnet.om**上传到Host侧的“/home/HwHiAiUser/models“目录下。
    
    图片要求如下:

    - 格式：jpg、png、bmp。
    - 输入图片宽度：16px~4096px之间的整数。
    - 输入图片高度：16px~4096px之间的整数。


## 运行<a name="zh-cn_topic_0167414508_section372782554919"></a>

1.  在MindSpore Studio所在Ubuntu服务器中，以HwHiAiUser用户SSH登录到Host侧。

    **ssh HwHiAiUser@**_host\_ip_

    对于Atlas 200 DK，host\_ip默认为192.168.1.2（USB连接）或者192.168.0.2（NIC连接）。

    对于AI加速云服务器，host\_ip即为当前MindSpore Studio所在服务器的IP地址。

2.  进入贯通网络的可执行文件所在路径。

    **cd \~/HIAI\_PROJECTS/ascend\_workspace/classification/out**

3.  执行应用程序。

    执行**run\_classification.py**脚本会将推理结果在执行终端直接打印显示。

    命令示例如下所示：

    **python3 run\_classification.py  -m  _\~/models/vgg16.om_  -w  _224_  -h  _224_  -i**

    **_./example.jpg_  -n  _10_**

    -   -m/--model\_path：离线模型存储路径。
    -   -w/model\_width：模型的输入图片宽度，为16\~4096之间的整数。
    -   -h/model\_height：模型的输入图片高度，为16\~4096之间的整数。
    -   -i/input\_path：输入图片的路径，可以是目录，表示当前目录下的所有图片都作为输入（可以指定多个输入）。
    -   -n/top\_n：输出前n个推理结果。

    其他详细参数请执行**python3 run\_classification.py --help**命令参见帮助信息。


## 网络模型及公共代码库下载<a name="zh-cn_topic_0167414508_section92241245122511"></a>

-   网络模型下载

    通用分类网络应用中使用的模型是经过转化后的适配Ascend 310芯片的模型，适配Ascend 310的模型的下载及原始网络模型的下载可参考[网络模型及公共代码库下载](#zh-cn_topic_0167414508_section92241245122511)。如果您有更好的模型，欢迎上传到[https://github.com/Ascend/models](https://github.com/Ascend/models)进行分享。

    将模型文件（.om文件）上传到Host侧任一属组为HwHiAiUser用户的目录。

    **表 1**  通用分类网络应用使用模型

    <a name="zh-cn_topic_0167414508_table1893112124312"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0167414508_row20932162164312"><th class="cellrowborder" valign="top" width="19.53%" id="mcps1.2.5.1.1"><p id="zh-cn_topic_0167414508_p199321521437"><a name="zh-cn_topic_0167414508_p199321521437"></a><a name="zh-cn_topic_0167414508_p199321521437"></a>模型名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="29.970000000000002%" id="mcps1.2.5.1.2"><p id="zh-cn_topic_0167414508_p1893211213432"><a name="zh-cn_topic_0167414508_p1893211213432"></a><a name="zh-cn_topic_0167414508_p1893211213432"></a>模型说明</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.01%" id="mcps1.2.5.1.3"><p id="zh-cn_topic_0167414508_p189321321439"><a name="zh-cn_topic_0167414508_p189321321439"></a><a name="zh-cn_topic_0167414508_p189321321439"></a>模型下载路径</p>
    </th>
    <th class="cellrowborder" valign="top" width="18.490000000000002%" id="mcps1.2.5.1.4"><p id="zh-cn_topic_0167414508_p9932102144311"><a name="zh-cn_topic_0167414508_p9932102144311"></a><a name="zh-cn_topic_0167414508_p9932102144311"></a>原始网络下载地址</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0167414508_row46451053974"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p38016264814"><a name="zh-cn_topic_0167414508_p38016264814"></a><a name="zh-cn_topic_0167414508_p38016264814"></a>图片分类推理模型（alexnet.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p8803267811"><a name="zh-cn_topic_0167414508_p8803267811"></a><a name="zh-cn_topic_0167414508_p8803267811"></a>此模型为<strong id="zh-cn_topic_0167414508_b112506266916"><a name="zh-cn_topic_0167414508_b112506266916"></a><a name="zh-cn_topic_0167414508_b112506266916"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p4801260818"><a name="zh-cn_topic_0167414508_p4801260818"></a><a name="zh-cn_topic_0167414508_p4801260818"></a>是基于Caffe的AlexNet模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p128072618818"><a name="zh-cn_topic_0167414508_p128072618818"></a><a name="zh-cn_topic_0167414508_p128072618818"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/alexnet目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p4801626587"><a name="zh-cn_topic_0167414508_p4801626587"></a><a name="zh-cn_topic_0167414508_p4801626587"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p128132612819"><a name="zh-cn_topic_0167414508_p128132612819"></a><a name="zh-cn_topic_0167414508_p128132612819"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/alexnet目录下的<span>README.md</span>文件获取。</p>
    <p id="zh-cn_topic_0167414508_p984534518555"><a name="zh-cn_topic_0167414508_p984534518555"></a><a name="zh-cn_topic_0167414508_p984534518555"></a><strong id="zh-cn_topic_0167414508_b17845645125512"><a name="zh-cn_topic_0167414508_b17845645125512"></a><a name="zh-cn_topic_0167414508_b17845645125512"></a>模型转换时注意事项：</strong></p>
    <p id="zh-cn_topic_0167414508_p1845174516559"><a name="zh-cn_topic_0167414508_p1845174516559"></a><a name="zh-cn_topic_0167414508_p1845174516559"></a>通用分类网络应用一次处理一张图片，所以转换时需要将Input Shape的N修改为1，如<a href="#zh-cn_topic_0167414508_fig20240124719920">图1</a>所示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row159579101382"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p14875119101115"><a name="zh-cn_topic_0167414508_p14875119101115"></a><a name="zh-cn_topic_0167414508_p14875119101115"></a>图片分类推理模型（caffenet.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p1587571914115"><a name="zh-cn_topic_0167414508_p1587571914115"></a><a name="zh-cn_topic_0167414508_p1587571914115"></a>此模型为<strong id="zh-cn_topic_0167414508_b15875191991111"><a name="zh-cn_topic_0167414508_b15875191991111"></a><a name="zh-cn_topic_0167414508_b15875191991111"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p1387581911113"><a name="zh-cn_topic_0167414508_p1387581911113"></a><a name="zh-cn_topic_0167414508_p1387581911113"></a>是基于Caffe的CaffeNet模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p12875719161117"><a name="zh-cn_topic_0167414508_p12875719161117"></a><a name="zh-cn_topic_0167414508_p12875719161117"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/caffenet目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p1087512196119"><a name="zh-cn_topic_0167414508_p1087512196119"></a><a name="zh-cn_topic_0167414508_p1087512196119"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p38752019131114"><a name="zh-cn_topic_0167414508_p38752019131114"></a><a name="zh-cn_topic_0167414508_p38752019131114"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/caffenet目录下的<span>README.md</span>文件获取。</p>
    <p id="zh-cn_topic_0167414508_p6542847111116"><a name="zh-cn_topic_0167414508_p6542847111116"></a><a name="zh-cn_topic_0167414508_p6542847111116"></a><strong id="zh-cn_topic_0167414508_b185428475110"><a name="zh-cn_topic_0167414508_b185428475110"></a><a name="zh-cn_topic_0167414508_b185428475110"></a>模型转换时注意事项：</strong></p>
    <p id="zh-cn_topic_0167414508_p554264715117"><a name="zh-cn_topic_0167414508_p554264715117"></a><a name="zh-cn_topic_0167414508_p554264715117"></a>通用分类网络应用一次处理一张图片，所以转换时需要将Input Shape的N修改为1，如<a href="#zh-cn_topic_0167414508_fig20240124719920">图1</a>所示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row316892191110"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p2992152117116"><a name="zh-cn_topic_0167414508_p2992152117116"></a><a name="zh-cn_topic_0167414508_p2992152117116"></a>图片分类推理模型（densenet.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p119923212112"><a name="zh-cn_topic_0167414508_p119923212112"></a><a name="zh-cn_topic_0167414508_p119923212112"></a>此模型为<strong id="zh-cn_topic_0167414508_b13992162131110"><a name="zh-cn_topic_0167414508_b13992162131110"></a><a name="zh-cn_topic_0167414508_b13992162131110"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p099252118116"><a name="zh-cn_topic_0167414508_p099252118116"></a><a name="zh-cn_topic_0167414508_p099252118116"></a>是基于Caffe的DenseNet121模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p159929213117"><a name="zh-cn_topic_0167414508_p159929213117"></a><a name="zh-cn_topic_0167414508_p159929213117"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/densenet目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p11992112119115"><a name="zh-cn_topic_0167414508_p11992112119115"></a><a name="zh-cn_topic_0167414508_p11992112119115"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p6992122121111"><a name="zh-cn_topic_0167414508_p6992122121111"></a><a name="zh-cn_topic_0167414508_p6992122121111"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/densenet目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row13785115171113"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p620742415114"><a name="zh-cn_topic_0167414508_p620742415114"></a><a name="zh-cn_topic_0167414508_p620742415114"></a>图片分类推理模型（googlenet.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p13207224191114"><a name="zh-cn_topic_0167414508_p13207224191114"></a><a name="zh-cn_topic_0167414508_p13207224191114"></a>此模型为<strong id="zh-cn_topic_0167414508_b6207122410118"><a name="zh-cn_topic_0167414508_b6207122410118"></a><a name="zh-cn_topic_0167414508_b6207122410118"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p1920712243116"><a name="zh-cn_topic_0167414508_p1920712243116"></a><a name="zh-cn_topic_0167414508_p1920712243116"></a>是基于Caffe的GoogLeNet模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p1720718241119"><a name="zh-cn_topic_0167414508_p1720718241119"></a><a name="zh-cn_topic_0167414508_p1720718241119"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/googlenet目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p192079240112"><a name="zh-cn_topic_0167414508_p192079240112"></a><a name="zh-cn_topic_0167414508_p192079240112"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p220712242115"><a name="zh-cn_topic_0167414508_p220712242115"></a><a name="zh-cn_topic_0167414508_p220712242115"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/googlenet目录下的<span>README.md</span>文件获取。</p>
    <p id="zh-cn_topic_0167414508_p1263175510116"><a name="zh-cn_topic_0167414508_p1263175510116"></a><a name="zh-cn_topic_0167414508_p1263175510116"></a><strong id="zh-cn_topic_0167414508_b156317556118"><a name="zh-cn_topic_0167414508_b156317556118"></a><a name="zh-cn_topic_0167414508_b156317556118"></a>模型转换时注意事项：</strong></p>
    <p id="zh-cn_topic_0167414508_p16313556115"><a name="zh-cn_topic_0167414508_p16313556115"></a><a name="zh-cn_topic_0167414508_p16313556115"></a>通用分类网络应用一次处理一张图片，所以转换时需要将Input Shaple的N修改为1，如<a href="#zh-cn_topic_0167414508_fig20240124719920">图1</a>所示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row8741916780"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p1856219253111"><a name="zh-cn_topic_0167414508_p1856219253111"></a><a name="zh-cn_topic_0167414508_p1856219253111"></a>图片分类推理模型（<span>inception_v2</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p3562182517117"><a name="zh-cn_topic_0167414508_p3562182517117"></a><a name="zh-cn_topic_0167414508_p3562182517117"></a>此模型为<strong id="zh-cn_topic_0167414508_b35627252115"><a name="zh-cn_topic_0167414508_b35627252115"></a><a name="zh-cn_topic_0167414508_b35627252115"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p10562132551115"><a name="zh-cn_topic_0167414508_p10562132551115"></a><a name="zh-cn_topic_0167414508_p10562132551115"></a>是基于Caffe的Inception V2模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p1256262501114"><a name="zh-cn_topic_0167414508_p1256262501114"></a><a name="zh-cn_topic_0167414508_p1256262501114"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>inception_v2</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p25624252119"><a name="zh-cn_topic_0167414508_p25624252119"></a><a name="zh-cn_topic_0167414508_p25624252119"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p5562112531118"><a name="zh-cn_topic_0167414508_p5562112531118"></a><a name="zh-cn_topic_0167414508_p5562112531118"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>inception_v2</span>目录下的<span>README.md</span>文件获取。</p>
    <p id="zh-cn_topic_0167414508_p12485515123"><a name="zh-cn_topic_0167414508_p12485515123"></a><a name="zh-cn_topic_0167414508_p12485515123"></a><strong id="zh-cn_topic_0167414508_b154858118128"><a name="zh-cn_topic_0167414508_b154858118128"></a><a name="zh-cn_topic_0167414508_b154858118128"></a>模型转换时注意事项：</strong></p>
    <p id="zh-cn_topic_0167414508_p048511131217"><a name="zh-cn_topic_0167414508_p048511131217"></a><a name="zh-cn_topic_0167414508_p048511131217"></a>通用分类网络应用一次处理一张图片，所以转换时需要将Input Shape的N修改为1，如<a href="#zh-cn_topic_0167414508_fig20240124719920">图1</a>所示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row9866134420103"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p1139610271116"><a name="zh-cn_topic_0167414508_p1139610271116"></a><a name="zh-cn_topic_0167414508_p1139610271116"></a>图片分类推理模型（<span>inception_v3</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p9396192751112"><a name="zh-cn_topic_0167414508_p9396192751112"></a><a name="zh-cn_topic_0167414508_p9396192751112"></a>此模型为<strong id="zh-cn_topic_0167414508_b3396527171110"><a name="zh-cn_topic_0167414508_b3396527171110"></a><a name="zh-cn_topic_0167414508_b3396527171110"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p11397192711117"><a name="zh-cn_topic_0167414508_p11397192711117"></a><a name="zh-cn_topic_0167414508_p11397192711117"></a>是基于Caffe的Inception V3模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p939792718117"><a name="zh-cn_topic_0167414508_p939792718117"></a><a name="zh-cn_topic_0167414508_p939792718117"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>inception_v3</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p113971727161113"><a name="zh-cn_topic_0167414508_p113971727161113"></a><a name="zh-cn_topic_0167414508_p113971727161113"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p83971627131115"><a name="zh-cn_topic_0167414508_p83971627131115"></a><a name="zh-cn_topic_0167414508_p83971627131115"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>inception_v3</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row17465348111014"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p106251329111119"><a name="zh-cn_topic_0167414508_p106251329111119"></a><a name="zh-cn_topic_0167414508_p106251329111119"></a>图片分类推理模型（<span>inception_v4</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p1262512901114"><a name="zh-cn_topic_0167414508_p1262512901114"></a><a name="zh-cn_topic_0167414508_p1262512901114"></a>此模型为<strong id="zh-cn_topic_0167414508_b66258292114"><a name="zh-cn_topic_0167414508_b66258292114"></a><a name="zh-cn_topic_0167414508_b66258292114"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p56252291113"><a name="zh-cn_topic_0167414508_p56252291113"></a><a name="zh-cn_topic_0167414508_p56252291113"></a>是基于Caffe的Inception V4模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p1262552951110"><a name="zh-cn_topic_0167414508_p1262552951110"></a><a name="zh-cn_topic_0167414508_p1262552951110"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>inception_v4</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p15625229171116"><a name="zh-cn_topic_0167414508_p15625229171116"></a><a name="zh-cn_topic_0167414508_p15625229171116"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p862511298110"><a name="zh-cn_topic_0167414508_p862511298110"></a><a name="zh-cn_topic_0167414508_p862511298110"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>inception_v4</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row979444613104"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p18346631111116"><a name="zh-cn_topic_0167414508_p18346631111116"></a><a name="zh-cn_topic_0167414508_p18346631111116"></a>图片分类推理模型（<span>mobilenet_v1</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p43461317114"><a name="zh-cn_topic_0167414508_p43461317114"></a><a name="zh-cn_topic_0167414508_p43461317114"></a>此模型为<strong id="zh-cn_topic_0167414508_b7346143114119"><a name="zh-cn_topic_0167414508_b7346143114119"></a><a name="zh-cn_topic_0167414508_b7346143114119"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p18346831181120"><a name="zh-cn_topic_0167414508_p18346831181120"></a><a name="zh-cn_topic_0167414508_p18346831181120"></a>是基于Caffe的MobileNet V1模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p3346113151116"><a name="zh-cn_topic_0167414508_p3346113151116"></a><a name="zh-cn_topic_0167414508_p3346113151116"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>mobilenet_v1</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p103461831131117"><a name="zh-cn_topic_0167414508_p103461831131117"></a><a name="zh-cn_topic_0167414508_p103461831131117"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p1934773117111"><a name="zh-cn_topic_0167414508_p1934773117111"></a><a name="zh-cn_topic_0167414508_p1934773117111"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>mobilenet_v1</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row689533810102"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p14326123381113"><a name="zh-cn_topic_0167414508_p14326123381113"></a><a name="zh-cn_topic_0167414508_p14326123381113"></a>图片分类推理模型（<span>mobilenet_v2</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p632643321113"><a name="zh-cn_topic_0167414508_p632643321113"></a><a name="zh-cn_topic_0167414508_p632643321113"></a>此模型为<strong id="zh-cn_topic_0167414508_b932643311118"><a name="zh-cn_topic_0167414508_b932643311118"></a><a name="zh-cn_topic_0167414508_b932643311118"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p532623311119"><a name="zh-cn_topic_0167414508_p532623311119"></a><a name="zh-cn_topic_0167414508_p532623311119"></a>是基于Caffe的MobileNet V2模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p6326193381119"><a name="zh-cn_topic_0167414508_p6326193381119"></a><a name="zh-cn_topic_0167414508_p6326193381119"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>mobilenet_v2</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p1832613335112"><a name="zh-cn_topic_0167414508_p1832613335112"></a><a name="zh-cn_topic_0167414508_p1832613335112"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p15327123371110"><a name="zh-cn_topic_0167414508_p15327123371110"></a><a name="zh-cn_topic_0167414508_p15327123371110"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>mobilenet_v2</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row1814664317105"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p1827573513115"><a name="zh-cn_topic_0167414508_p1827573513115"></a><a name="zh-cn_topic_0167414508_p1827573513115"></a>图片分类推理模型（<span>resnet18</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p9275113591110"><a name="zh-cn_topic_0167414508_p9275113591110"></a><a name="zh-cn_topic_0167414508_p9275113591110"></a>此模型为<strong id="zh-cn_topic_0167414508_b162758353113"><a name="zh-cn_topic_0167414508_b162758353113"></a><a name="zh-cn_topic_0167414508_b162758353113"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p1227523513114"><a name="zh-cn_topic_0167414508_p1227523513114"></a><a name="zh-cn_topic_0167414508_p1227523513114"></a>是基于Caffe的ResNet 18模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p5275143510111"><a name="zh-cn_topic_0167414508_p5275143510111"></a><a name="zh-cn_topic_0167414508_p5275143510111"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>resnet18</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p1327533551110"><a name="zh-cn_topic_0167414508_p1327533551110"></a><a name="zh-cn_topic_0167414508_p1327533551110"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p122751235101111"><a name="zh-cn_topic_0167414508_p122751235101111"></a><a name="zh-cn_topic_0167414508_p122751235101111"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>resnet18</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row441394141015"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p6695133711118"><a name="zh-cn_topic_0167414508_p6695133711118"></a><a name="zh-cn_topic_0167414508_p6695133711118"></a>图片分类推理模型（<span>resnet50</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p5695163791110"><a name="zh-cn_topic_0167414508_p5695163791110"></a><a name="zh-cn_topic_0167414508_p5695163791110"></a>此模型为<strong id="zh-cn_topic_0167414508_b166953371114"><a name="zh-cn_topic_0167414508_b166953371114"></a><a name="zh-cn_topic_0167414508_b166953371114"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p66951937161112"><a name="zh-cn_topic_0167414508_p66951937161112"></a><a name="zh-cn_topic_0167414508_p66951937161112"></a>是基于Caffe的ResNet 50模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p18695183720114"><a name="zh-cn_topic_0167414508_p18695183720114"></a><a name="zh-cn_topic_0167414508_p18695183720114"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>resnet50</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p269514376113"><a name="zh-cn_topic_0167414508_p269514376113"></a><a name="zh-cn_topic_0167414508_p269514376113"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p569693714114"><a name="zh-cn_topic_0167414508_p569693714114"></a><a name="zh-cn_topic_0167414508_p569693714114"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>resnet50</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row37251614782"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p059819395113"><a name="zh-cn_topic_0167414508_p059819395113"></a><a name="zh-cn_topic_0167414508_p059819395113"></a>图片分类推理模型（<span>resnet101</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p1598123971117"><a name="zh-cn_topic_0167414508_p1598123971117"></a><a name="zh-cn_topic_0167414508_p1598123971117"></a>此模型为<strong id="zh-cn_topic_0167414508_b959823915114"><a name="zh-cn_topic_0167414508_b959823915114"></a><a name="zh-cn_topic_0167414508_b959823915114"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p9598113981116"><a name="zh-cn_topic_0167414508_p9598113981116"></a><a name="zh-cn_topic_0167414508_p9598113981116"></a>是基于Caffe的ResNet 101模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p1959811392112"><a name="zh-cn_topic_0167414508_p1959811392112"></a><a name="zh-cn_topic_0167414508_p1959811392112"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>resnet101</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p859811399116"><a name="zh-cn_topic_0167414508_p859811399116"></a><a name="zh-cn_topic_0167414508_p859811399116"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p8598163917114"><a name="zh-cn_topic_0167414508_p8598163917114"></a><a name="zh-cn_topic_0167414508_p8598163917114"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>resnet101</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row3565755811"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p12320164191115"><a name="zh-cn_topic_0167414508_p12320164191115"></a><a name="zh-cn_topic_0167414508_p12320164191115"></a>图片分类推理模型（<span>resnet152</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p532054151113"><a name="zh-cn_topic_0167414508_p532054151113"></a><a name="zh-cn_topic_0167414508_p532054151113"></a>此模型为<strong id="zh-cn_topic_0167414508_b532017413119"><a name="zh-cn_topic_0167414508_b532017413119"></a><a name="zh-cn_topic_0167414508_b532017413119"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p2320144171115"><a name="zh-cn_topic_0167414508_p2320144171115"></a><a name="zh-cn_topic_0167414508_p2320144171115"></a>是基于Caffe的ResNet 152模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p183201741111113"><a name="zh-cn_topic_0167414508_p183201741111113"></a><a name="zh-cn_topic_0167414508_p183201741111113"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>resnet152</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p93201541141118"><a name="zh-cn_topic_0167414508_p93201541141118"></a><a name="zh-cn_topic_0167414508_p93201541141118"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p5321144117119"><a name="zh-cn_topic_0167414508_p5321144117119"></a><a name="zh-cn_topic_0167414508_p5321144117119"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>resnet152</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row696519012818"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p422234301120"><a name="zh-cn_topic_0167414508_p422234301120"></a><a name="zh-cn_topic_0167414508_p422234301120"></a>图片分类推理模型（<span>vgg16</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p1522374351117"><a name="zh-cn_topic_0167414508_p1522374351117"></a><a name="zh-cn_topic_0167414508_p1522374351117"></a>此模型为<strong id="zh-cn_topic_0167414508_b8223743121118"><a name="zh-cn_topic_0167414508_b8223743121118"></a><a name="zh-cn_topic_0167414508_b8223743121118"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p16223184310112"><a name="zh-cn_topic_0167414508_p16223184310112"></a><a name="zh-cn_topic_0167414508_p16223184310112"></a>是基于Caffe的VGG16模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p5223184371117"><a name="zh-cn_topic_0167414508_p5223184371117"></a><a name="zh-cn_topic_0167414508_p5223184371117"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>vgg16</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p10223144311117"><a name="zh-cn_topic_0167414508_p10223144311117"></a><a name="zh-cn_topic_0167414508_p10223144311117"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p1422334316113"><a name="zh-cn_topic_0167414508_p1422334316113"></a><a name="zh-cn_topic_0167414508_p1422334316113"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>vgg16</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row6549133817"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p85381445201113"><a name="zh-cn_topic_0167414508_p85381445201113"></a><a name="zh-cn_topic_0167414508_p85381445201113"></a>图片分类推理模型（<span>vgg19</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p85381645121115"><a name="zh-cn_topic_0167414508_p85381645121115"></a><a name="zh-cn_topic_0167414508_p85381645121115"></a>此模型为<strong id="zh-cn_topic_0167414508_b953854518118"><a name="zh-cn_topic_0167414508_b953854518118"></a><a name="zh-cn_topic_0167414508_b953854518118"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p1753844514117"><a name="zh-cn_topic_0167414508_p1753844514117"></a><a name="zh-cn_topic_0167414508_p1753844514117"></a>是基于Caffe的VGG19模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p553813451112"><a name="zh-cn_topic_0167414508_p553813451112"></a><a name="zh-cn_topic_0167414508_p553813451112"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>vgg19</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p053894518111"><a name="zh-cn_topic_0167414508_p053894518111"></a><a name="zh-cn_topic_0167414508_p053894518111"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p1253854581112"><a name="zh-cn_topic_0167414508_p1253854581112"></a><a name="zh-cn_topic_0167414508_p1253854581112"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>vgg19</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row33092581075"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p265315476115"><a name="zh-cn_topic_0167414508_p265315476115"></a><a name="zh-cn_topic_0167414508_p265315476115"></a>图片分类推理模型（<span>squeezenet</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p17653194714118"><a name="zh-cn_topic_0167414508_p17653194714118"></a><a name="zh-cn_topic_0167414508_p17653194714118"></a>此模型为<strong id="zh-cn_topic_0167414508_b4653194713111"><a name="zh-cn_topic_0167414508_b4653194713111"></a><a name="zh-cn_topic_0167414508_b4653194713111"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p6653194718113"><a name="zh-cn_topic_0167414508_p6653194718113"></a><a name="zh-cn_topic_0167414508_p6653194718113"></a>是基于Caffe的<span>SqueezeNet</span>模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p3653184712114"><a name="zh-cn_topic_0167414508_p3653184712114"></a><a name="zh-cn_topic_0167414508_p3653184712114"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>squeezenet</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p1065384718113"><a name="zh-cn_topic_0167414508_p1065384718113"></a><a name="zh-cn_topic_0167414508_p1065384718113"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p86531547121116"><a name="zh-cn_topic_0167414508_p86531547121116"></a><a name="zh-cn_topic_0167414508_p86531547121116"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>squeezenet</span>目录下的<span>README.md</span>文件获取。</p>
    <p id="zh-cn_topic_0167414508_p169381419151217"><a name="zh-cn_topic_0167414508_p169381419151217"></a><a name="zh-cn_topic_0167414508_p169381419151217"></a><strong id="zh-cn_topic_0167414508_b1993851971218"><a name="zh-cn_topic_0167414508_b1993851971218"></a><a name="zh-cn_topic_0167414508_b1993851971218"></a>模型转换时注意事项：</strong></p>
    <p id="zh-cn_topic_0167414508_p79387192124"><a name="zh-cn_topic_0167414508_p79387192124"></a><a name="zh-cn_topic_0167414508_p79387192124"></a>通用分类网络应用一次处理一张图片，所以转换时需要将Input Shape的N修改为1，如<a href="#zh-cn_topic_0167414508_fig20240124719920">图1</a>所示。</p>
    </td>
    </tr>
    <tr id="zh-cn_topic_0167414508_row2011118432011"><td class="cellrowborder" valign="top" width="19.53%" headers="mcps1.2.5.1.1 "><p id="zh-cn_topic_0167414508_p8807195615216"><a name="zh-cn_topic_0167414508_p8807195615216"></a><a name="zh-cn_topic_0167414508_p8807195615216"></a>图片分类推理模型（<span>dpn98</span>.om）</p>
    </td>
    <td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.2.5.1.2 "><p id="zh-cn_topic_0167414508_p158071856152116"><a name="zh-cn_topic_0167414508_p158071856152116"></a><a name="zh-cn_topic_0167414508_p158071856152116"></a>此模型为<strong id="zh-cn_topic_0167414508_b1780714563211"><a name="zh-cn_topic_0167414508_b1780714563211"></a><a name="zh-cn_topic_0167414508_b1780714563211"></a>通用分类网络</strong>应用中使用的模型。</p>
    <p id="zh-cn_topic_0167414508_p1580725614215"><a name="zh-cn_topic_0167414508_p1580725614215"></a><a name="zh-cn_topic_0167414508_p1580725614215"></a>是基于Caffe的<span>dpn98</span>模型。</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.01%" headers="mcps1.2.5.1.3 "><p id="zh-cn_topic_0167414508_p10808195622117"><a name="zh-cn_topic_0167414508_p10808195622117"></a><a name="zh-cn_topic_0167414508_p10808195622117"></a>请从<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>dpn98</span>目录中下载。</p>
    <p id="zh-cn_topic_0167414508_p3808175642119"><a name="zh-cn_topic_0167414508_p3808175642119"></a><a name="zh-cn_topic_0167414508_p3808175642119"></a>对应版本说明请参考当前目录下的<span>README.md</span>文件。</p>
    </td>
    <td class="cellrowborder" valign="top" width="18.490000000000002%" headers="mcps1.2.5.1.4 "><p id="zh-cn_topic_0167414508_p1280835672115"><a name="zh-cn_topic_0167414508_p1280835672115"></a><a name="zh-cn_topic_0167414508_p1280835672115"></a>请参考<a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a>仓的computer_vision/classification/<span>dpn98</span>目录下的<span>README.md</span>文件获取。</p>
    </td>
    </tr>
    </tbody>
    </table>

    **图 1**  通用分类网络模型转换配置参考<a name="zh-cn_topic_0167414508_fig20240124719920"></a>  
    ![](doc/source/img/通用分类网络模型转换配置参考.png "通用分类网络模型转换配置参考")

    由于通用分类网络应用每次处理一张图片，所以需要将模型转换时的Batch修改为1。

-   依赖代码库下载

    将依赖的软件库下载到“sample-classification/script“目录下。

    **表 2**  依赖代码库下载

    <a name="zh-cn_topic_0167414508_table1140133816250"></a>
    <table><thead align="left"><tr id="zh-cn_topic_0167414508_row414003817251"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="zh-cn_topic_0167414508_p5139163817258"><a name="zh-cn_topic_0167414508_p5139163817258"></a><a name="zh-cn_topic_0167414508_p5139163817258"></a>模块名称</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="zh-cn_topic_0167414508_p1139183842519"><a name="zh-cn_topic_0167414508_p1139183842519"></a><a name="zh-cn_topic_0167414508_p1139183842519"></a>模块描述</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="zh-cn_topic_0167414508_p1139193814255"><a name="zh-cn_topic_0167414508_p1139193814255"></a><a name="zh-cn_topic_0167414508_p1139193814255"></a>下载地址</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="zh-cn_topic_0167414508_row1714093811252"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="zh-cn_topic_0167414508_p1614033872510"><a name="zh-cn_topic_0167414508_p1614033872510"></a><a name="zh-cn_topic_0167414508_p1614033872510"></a>EZDVPP</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="zh-cn_topic_0167414508_p51401538122517"><a name="zh-cn_topic_0167414508_p51401538122517"></a><a name="zh-cn_topic_0167414508_p51401538122517"></a>对DVPP接口进行了封装，提供对图片/视频的处理能力。</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="zh-cn_topic_0167414508_p17140143816256"><a name="zh-cn_topic_0167414508_p17140143816256"></a><a name="zh-cn_topic_0167414508_p17140143816256"></a><a href="https://github.com/Ascend/sdk-ezdvpp" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/sdk-ezdvpp</a></p>
    <p id="zh-cn_topic_0167414508_p3140133812258"><a name="zh-cn_topic_0167414508_p3140133812258"></a><a name="zh-cn_topic_0167414508_p3140133812258"></a>下载后请保持文件夹名称为ezdvpp。</p>
    </td>
    </tr>
    </tbody>
    </table>


