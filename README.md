EN|[CN](README_cn.md)

The classification classification application runs on the Atlas 200 DK or the AI acceleration cloud server and implements the inference function by using a common classification network, and the first  _n_  inference results are output.

## Prerequisites<a name="en-us_topic_0167438951_section412314183119"></a>

Before using an open source application, ensure that:

-   MindSpore Studio has been installed.
-   The Atlas 200 DK developer board has been connected to MindSpore Studio, the cross compiler has been installed, the SD card has been prepared, and basic information has been configured. 

## Software Preparation<a name="en-us_topic_0167438951_section126492814528"></a>

Before running the application, obtain the source code package and configure the environment as follows.

1.  Obtain the source code package.

    Download all the code in the sample-classification repository at  [https://github.com/Ascend/sample-classification](https://github.com/Ascend/sample-classification)  to any directory on Ubuntu Server where MindSpore Studio is located as the MindSpore Studio installation user, for example,  _/home/ascend/sample-classification_.

2.  Log in to Ubuntu Server where MindSpore Studio is located as the MindSpore Studio installation user and set the environment variable  **DDK\_HOME**.

    **vim \~/.bashrc**

    Run the following commands to add the environment variables  **DDK\_HOME**  and  **LD\_LIBRARY\_PATH**  to the last line:

    **export DDK\_HOME=/home/XXX/tools/che/ddk/ddk**

    **export LD\_LIBRARY\_PATH=$DDK\_HOME/uihost/lib**

    >![](doc/source/img/icon-note.gif) **NOTE:**   
    >-   **XXX**  indicates the MindSpore Studio installation user, and  **/home/XXX/tools**  indicates the default installation path of the DDK.  
    >-   If the environment variables have been added, skip this step.  

    Enter  **:wq!**  to save and exit.

    Run the following command for the environment variable to take effect:

    **source \~/.bashrc**


## Deployment<a name="en-us_topic_0167438951_section1823144520529"></a>

1.  Access the root directory where the classification application code is located as the MindSpore Studio installation user, for example,  _**/home/ascend/sample-classification**_.
2.  Run the deployment script to prepare the project environment, including compiling and deploying the ascenddk public library and application.

    bash deploy.sh  _host\_ip_ _model\_mode_

    -   _host\_ip_: For the Atlas 200 DK developer board, this parameter indicates the IP address of the developer board.For the AI acceleration cloud server, this parameter indicates the IP address of the host.
    -   _model\_mode_  indicates the deployment mode of the model file. The default setting is  **internet**.
        -   **local**: If the Ubuntu system where MindSpore Studio is located is not connected to the network, use the local mode. In this case, download the dependent common code library ezdvpp to the  **sample-classification/script**  directory by referring to the  [Downloading Network Models and and Dependency Code Library](#en-us_topic_0167438951_section13446115712539).
        -   **internet**: Indicates the online deployment mode. If the Ubuntu system where MindSpore Studio is located is connected to the network, use the Internet mode. In this case, download the dependency code library ezdvpp online.


    Example command:

    **bash deploy.sh 192.168.1.2 internet**

3.  Upload the offline model file to be used and the image which requires inference to the directory of the  **HwHiAiUser**  user on the Host. For details, see  [Downloading Network Models and and Dependency Code Library](#en-us_topic_0167438951_section13446115712539).

    For example, upload the model file  **alexnet.om**  to the  **/home/HwHiAiUser/models**  directory on the host.

    The image requirements are as follows:
    - Format: JPG, PNG, and BMP.
    - Width of the input image: the value is an integer ranging from 16px to 4096px.
    - Height of the input image: the value is an integer ranging from 16px to 4096px.


## Running<a name="en-us_topic_0167438951_section1665916172539"></a>

1.  Log in to the Host as the  **HwHiAiUser**  user in SSH mode on Ubuntu Server where MindSpore Studio is located.

    **ssh HwHiAiUser@**_host\_ip_

    For the Atlas 200 DK, the default value of  _**host\_ip**_  is  **192.168.1.2**  \(USB connection mode\) or  **192.168.0.2**  \(NIC connection mode\).

    For the AI acceleration cloud server,  _**host\_ip**_  indicates the IP address of the server where MindSpore Studio is located.

2.  Go to the path of the executable file of classification application.

    **cd \~/HIAI\_PROJECTS/ascend\_workspace/classification/out**

3.  Run the application.

    Run the  **run\_classification.py**  script to print the inference result on the execution terminal.

    Example command:

    **python3 run\_classification.py -m  _\~/models/vgg16.om_  -w  _224_  -h  _224_  -i**

    **_./example.jpg_  -n  _10_**

    -   **-m/--model\_path**: path for storing offline models
    -   **-w/model\_width**: width of the input image of a model. The value is an integer ranging from 16 to 4096.
    -   **-h/model\_height**: height of the input image of a model. The value is an integer ranging from 16 to 4096.
    -   **-i/input\_path**: path of the input image. It can be a directory, indicating that all images in the current directory are used as input. \(Multiple inputs can be specified\).
    -   **-n/top\_n**: the first  _n_  inference results that are output

    For other parameters, run the  **python3 run\_classification.py --help**  command. For details, see the help information.


## Downloading Network Models and and Dependency Code Library<a name="en-us_topic_0167438951_section13446115712539"></a>

-   Downloading network models

    The models used in the application are converted models that adapt to the Ascend 310 chipset. For details about how to download this kind of models and the original network models, see  [Table 1](#en-us_topic_0167438951_table0531392153). If you have a better model solution, you are welcome to share it at  [https://github.com/Ascend/models](https://github.com/Ascend/models).

    Upload the network model files (.om files) to the directory of the  **HwHiAiUser**  user on the Host.

    **Table  1**  Models used in Classification Application

    <a name="en-us_topic_0167438951_table0531392153"></a>
    <table><thead align="left"><tr id="en-us_topic_0167438951_row1154103991514"><th class="cellrowborder" valign="top" width="15.841584158415841%" id="mcps1.2.5.1.1"><p id="en-us_topic_0167438951_p195418397155"><a name="en-us_topic_0167438951_p195418397155"></a><a name="en-us_topic_0167438951_p195418397155"></a>Model Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="21.782178217821784%" id="mcps1.2.5.1.2"><p id="en-us_topic_0167438951_p1054539151519"><a name="en-us_topic_0167438951_p1054539151519"></a><a name="en-us_topic_0167438951_p1054539151519"></a>Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="28.71287128712871%" id="mcps1.2.5.1.3"><p id="en-us_topic_0167438951_p387083117108"><a name="en-us_topic_0167438951_p387083117108"></a><a name="en-us_topic_0167438951_p387083117108"></a>Model Download Path</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.663366336633665%" id="mcps1.2.5.1.4"><p id="en-us_topic_0167438951_p35412397154"><a name="en-us_topic_0167438951_p35412397154"></a><a name="en-us_topic_0167438951_p35412397154"></a>Original Network Download Address</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0167438951_row46451053974"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p38016264814"><a name="en-us_topic_0167438951_p38016264814"></a><a name="en-us_topic_0167438951_p38016264814"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b145645810435"><a name="en-us_topic_0167438951_b145645810435"></a><a name="en-us_topic_0167438951_b145645810435"></a>alexnet.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p8803267811"><a name="en-us_topic_0167438951_p8803267811"></a><a name="en-us_topic_0167438951_p8803267811"></a>This model is used in the <strong id="en-us_topic_0167438951_b33551153115614"><a name="en-us_topic_0167438951_b33551153115614"></a><a name="en-us_topic_0167438951_b33551153115614"></a>classification application</strong> application.</p>
    <p id="en-us_topic_0167438951_p4801260818"><a name="en-us_topic_0167438951_p4801260818"></a><a name="en-us_topic_0167438951_p4801260818"></a>It is an AlexNet model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p128072618818"><a name="en-us_topic_0167438951_p128072618818"></a><a name="en-us_topic_0167438951_p128072618818"></a>Download the model from the <strong id="en-us_topic_0167438951_b927977407"><a name="en-us_topic_0167438951_b927977407"></a><a name="en-us_topic_0167438951_b927977407"></a>computer_vision/classification/alexnet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p4801626587"><a name="en-us_topic_0167438951_p4801626587"></a><a name="en-us_topic_0167438951_p4801626587"></a>For the version description, see the <strong id="en-us_topic_0167438951_b116611920124613"><a name="en-us_topic_0167438951_b116611920124613"></a><a name="en-us_topic_0167438951_b116611920124613"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p128132612819"><a name="en-us_topic_0167438951_p128132612819"></a><a name="en-us_topic_0167438951_p128132612819"></a>For details, see the <strong id="en-us_topic_0167438951_b7661623134619"><a name="en-us_topic_0167438951_b7661623134619"></a><a name="en-us_topic_0167438951_b7661623134619"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b19661223174616"><a name="en-us_topic_0167438951_b19661223174616"></a><a name="en-us_topic_0167438951_b19661223174616"></a>computer_vision/classification/alexnet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p177156532915"><a name="en-us_topic_0167438951_p177156532915"></a><a name="en-us_topic_0167438951_p177156532915"></a><strong id="en-us_topic_0167438951_b1026464240"><a name="en-us_topic_0167438951_b1026464240"></a><a name="en-us_topic_0167438951_b1026464240"></a>Precautions during model conversion:</strong></p>
    <p id="en-us_topic_0167438951_p79199202017"><a name="en-us_topic_0167438951_p79199202017"></a><a name="en-us_topic_0167438951_p79199202017"></a>The classification application processes one picture at a time. Therefore, the value of N in <strong id="en-us_topic_0167438951_b208905419213"><a name="en-us_topic_0167438951_b208905419213"></a><a name="en-us_topic_0167438951_b208905419213"></a>Input Shaple</strong> needs to be changed to 1 during conversion, as shown in <a href="#en-us_topic_0167438951_fig20240124719920">Figure 1</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row159579101382"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p14875119101115"><a name="en-us_topic_0167438951_p14875119101115"></a><a name="en-us_topic_0167438951_p14875119101115"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b1098923719462"><a name="en-us_topic_0167438951_b1098923719462"></a><a name="en-us_topic_0167438951_b1098923719462"></a>caffenet.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p1587571914115"><a name="en-us_topic_0167438951_p1587571914115"></a><a name="en-us_topic_0167438951_p1587571914115"></a>This model is used in the <strong id="en-us_topic_0167438951_b1339518579"><a name="en-us_topic_0167438951_b1339518579"></a><a name="en-us_topic_0167438951_b1339518579"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p1387581911113"><a name="en-us_topic_0167438951_p1387581911113"></a><a name="en-us_topic_0167438951_p1387581911113"></a>It is a CaffeNet model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p12875719161117"><a name="en-us_topic_0167438951_p12875719161117"></a><a name="en-us_topic_0167438951_p12875719161117"></a>Download the model from the <strong id="en-us_topic_0167438951_b43333586461"><a name="en-us_topic_0167438951_b43333586461"></a><a name="en-us_topic_0167438951_b43333586461"></a>computer_vision/classification/caffenet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p1087512196119"><a name="en-us_topic_0167438951_p1087512196119"></a><a name="en-us_topic_0167438951_p1087512196119"></a>For the version description, see the <strong id="en-us_topic_0167438951_b1729101124719"><a name="en-us_topic_0167438951_b1729101124719"></a><a name="en-us_topic_0167438951_b1729101124719"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p38752019131114"><a name="en-us_topic_0167438951_p38752019131114"></a><a name="en-us_topic_0167438951_p38752019131114"></a>For details, see the <strong id="en-us_topic_0167438951_b2276171444719"><a name="en-us_topic_0167438951_b2276171444719"></a><a name="en-us_topic_0167438951_b2276171444719"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b927631424718"><a name="en-us_topic_0167438951_b927631424718"></a><a name="en-us_topic_0167438951_b927631424718"></a>computer_vision/classification/caffenet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p114206227238"><a name="en-us_topic_0167438951_p114206227238"></a><a name="en-us_topic_0167438951_p114206227238"></a><strong id="en-us_topic_0167438951_b842092220233"><a name="en-us_topic_0167438951_b842092220233"></a><a name="en-us_topic_0167438951_b842092220233"></a>Precautions during model conversion:</strong></p>
    <p id="en-us_topic_0167438951_p11420122215234"><a name="en-us_topic_0167438951_p11420122215234"></a><a name="en-us_topic_0167438951_p11420122215234"></a>The classification application processes one picture at a time. Therefore, the value of N in <strong id="en-us_topic_0167438951_b1542062212238"><a name="en-us_topic_0167438951_b1542062212238"></a><a name="en-us_topic_0167438951_b1542062212238"></a>Input Shaple</strong> needs to be changed to 1 during conversion, as shown in <a href="#en-us_topic_0167438951_fig20240124719920">Figure 1</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row316892191110"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p2992152117116"><a name="en-us_topic_0167438951_p2992152117116"></a><a name="en-us_topic_0167438951_p2992152117116"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b176196308471"><a name="en-us_topic_0167438951_b176196308471"></a><a name="en-us_topic_0167438951_b176196308471"></a>densenet.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p119923212112"><a name="en-us_topic_0167438951_p119923212112"></a><a name="en-us_topic_0167438951_p119923212112"></a>This model is used in the <strong id="en-us_topic_0167438951_b638618915573"><a name="en-us_topic_0167438951_b638618915573"></a><a name="en-us_topic_0167438951_b638618915573"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p099252118116"><a name="en-us_topic_0167438951_p099252118116"></a><a name="en-us_topic_0167438951_p099252118116"></a>It is a DenseNet121 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p159929213117"><a name="en-us_topic_0167438951_p159929213117"></a><a name="en-us_topic_0167438951_p159929213117"></a>Download the model from the <strong id="en-us_topic_0167438951_b172608531476"><a name="en-us_topic_0167438951_b172608531476"></a><a name="en-us_topic_0167438951_b172608531476"></a>computer_vision/classification/densenet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p11992112119115"><a name="en-us_topic_0167438951_p11992112119115"></a><a name="en-us_topic_0167438951_p11992112119115"></a>For the version description, see the <strong id="en-us_topic_0167438951_b194221553486"><a name="en-us_topic_0167438951_b194221553486"></a><a name="en-us_topic_0167438951_b194221553486"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p6992122121111"><a name="en-us_topic_0167438951_p6992122121111"></a><a name="en-us_topic_0167438951_p6992122121111"></a>For details, see the <strong id="en-us_topic_0167438951_b939119864818"><a name="en-us_topic_0167438951_b939119864818"></a><a name="en-us_topic_0167438951_b939119864818"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b43915844818"><a name="en-us_topic_0167438951_b43915844818"></a><a name="en-us_topic_0167438951_b43915844818"></a>computer_vision/classification/densenet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row13785115171113"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p620742415114"><a name="en-us_topic_0167438951_p620742415114"></a><a name="en-us_topic_0167438951_p620742415114"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b2032736144815"><a name="en-us_topic_0167438951_b2032736144815"></a><a name="en-us_topic_0167438951_b2032736144815"></a>googlenet.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p13207224191114"><a name="en-us_topic_0167438951_p13207224191114"></a><a name="en-us_topic_0167438951_p13207224191114"></a>This model is used in the <strong id="en-us_topic_0167438951_b1868361815579"><a name="en-us_topic_0167438951_b1868361815579"></a><a name="en-us_topic_0167438951_b1868361815579"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p1920712243116"><a name="en-us_topic_0167438951_p1920712243116"></a><a name="en-us_topic_0167438951_p1920712243116"></a>It is a GoogLeNet model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p1720718241119"><a name="en-us_topic_0167438951_p1720718241119"></a><a name="en-us_topic_0167438951_p1720718241119"></a>Download the model from the <strong id="en-us_topic_0167438951_b10657105310488"><a name="en-us_topic_0167438951_b10657105310488"></a><a name="en-us_topic_0167438951_b10657105310488"></a>computer_vision/classification/googlenet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p192079240112"><a name="en-us_topic_0167438951_p192079240112"></a><a name="en-us_topic_0167438951_p192079240112"></a>For the version description, see the <strong id="en-us_topic_0167438951_b935017311496"><a name="en-us_topic_0167438951_b935017311496"></a><a name="en-us_topic_0167438951_b935017311496"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p220712242115"><a name="en-us_topic_0167438951_p220712242115"></a><a name="en-us_topic_0167438951_p220712242115"></a>For details, see the <strong id="en-us_topic_0167438951_b118971848492"><a name="en-us_topic_0167438951_b118971848492"></a><a name="en-us_topic_0167438951_b118971848492"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b089744114912"><a name="en-us_topic_0167438951_b089744114912"></a><a name="en-us_topic_0167438951_b089744114912"></a>computer_vision/classification/googlenet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p2093722813233"><a name="en-us_topic_0167438951_p2093722813233"></a><a name="en-us_topic_0167438951_p2093722813233"></a><strong id="en-us_topic_0167438951_b59379285232"><a name="en-us_topic_0167438951_b59379285232"></a><a name="en-us_topic_0167438951_b59379285232"></a>Precautions during model conversion:</strong></p>
    <p id="en-us_topic_0167438951_p7937528112310"><a name="en-us_topic_0167438951_p7937528112310"></a><a name="en-us_topic_0167438951_p7937528112310"></a>The classification application processes one picture at a time. Therefore, the value of N in <strong id="en-us_topic_0167438951_b199371728202320"><a name="en-us_topic_0167438951_b199371728202320"></a><a name="en-us_topic_0167438951_b199371728202320"></a>Input Shaple</strong> needs to be changed to 1 during conversion, as shown in <a href="#en-us_topic_0167438951_fig20240124719920">Figure 1</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row8741916780"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p1856219253111"><a name="en-us_topic_0167438951_p1856219253111"></a><a name="en-us_topic_0167438951_p1856219253111"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b81005144491"><a name="en-us_topic_0167438951_b81005144491"></a><a name="en-us_topic_0167438951_b81005144491"></a>inception_v2.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p3562182517117"><a name="en-us_topic_0167438951_p3562182517117"></a><a name="en-us_topic_0167438951_p3562182517117"></a>This model is used in the <strong id="en-us_topic_0167438951_b1113613266572"><a name="en-us_topic_0167438951_b1113613266572"></a><a name="en-us_topic_0167438951_b1113613266572"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p10562132551115"><a name="en-us_topic_0167438951_p10562132551115"></a><a name="en-us_topic_0167438951_p10562132551115"></a>It is an Inception V2 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p1256262501114"><a name="en-us_topic_0167438951_p1256262501114"></a><a name="en-us_topic_0167438951_p1256262501114"></a>Download the model from the <strong id="en-us_topic_0167438951_b695953310491"><a name="en-us_topic_0167438951_b695953310491"></a><a name="en-us_topic_0167438951_b695953310491"></a>computer_vision/classification/inception_v2</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p25624252119"><a name="en-us_topic_0167438951_p25624252119"></a><a name="en-us_topic_0167438951_p25624252119"></a>For the version description, see the <strong id="en-us_topic_0167438951_b196009442498"><a name="en-us_topic_0167438951_b196009442498"></a><a name="en-us_topic_0167438951_b196009442498"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p5562112531118"><a name="en-us_topic_0167438951_p5562112531118"></a><a name="en-us_topic_0167438951_p5562112531118"></a>For details, see the <strong id="en-us_topic_0167438951_b336635014910"><a name="en-us_topic_0167438951_b336635014910"></a><a name="en-us_topic_0167438951_b336635014910"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b63668504490"><a name="en-us_topic_0167438951_b63668504490"></a><a name="en-us_topic_0167438951_b63668504490"></a>computer_vision/classification/inception_v2</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p45473472311"><a name="en-us_topic_0167438951_p45473472311"></a><a name="en-us_topic_0167438951_p45473472311"></a><strong id="en-us_topic_0167438951_b1354183416239"><a name="en-us_topic_0167438951_b1354183416239"></a><a name="en-us_topic_0167438951_b1354183416239"></a>Precautions during model conversion:</strong></p>
    <p id="en-us_topic_0167438951_p554133417231"><a name="en-us_topic_0167438951_p554133417231"></a><a name="en-us_topic_0167438951_p554133417231"></a>The classification application processes one picture at a time. Therefore, the value of N in <strong id="en-us_topic_0167438951_b10541341239"><a name="en-us_topic_0167438951_b10541341239"></a><a name="en-us_topic_0167438951_b10541341239"></a>Input Shaple</strong> needs to be changed to 1 during conversion, as shown in <a href="#en-us_topic_0167438951_fig20240124719920">Figure 1</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row9866134420103"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p1139610271116"><a name="en-us_topic_0167438951_p1139610271116"></a><a name="en-us_topic_0167438951_p1139610271116"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b10741115834910"><a name="en-us_topic_0167438951_b10741115834910"></a><a name="en-us_topic_0167438951_b10741115834910"></a>inception_v3.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p9396192751112"><a name="en-us_topic_0167438951_p9396192751112"></a><a name="en-us_topic_0167438951_p9396192751112"></a>This model is used in the <strong id="en-us_topic_0167438951_b1641843475711"><a name="en-us_topic_0167438951_b1641843475711"></a><a name="en-us_topic_0167438951_b1641843475711"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p11397192711117"><a name="en-us_topic_0167438951_p11397192711117"></a><a name="en-us_topic_0167438951_p11397192711117"></a>It is an Inception V3 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p939792718117"><a name="en-us_topic_0167438951_p939792718117"></a><a name="en-us_topic_0167438951_p939792718117"></a>Download the model from the <strong id="en-us_topic_0167438951_b91532136500"><a name="en-us_topic_0167438951_b91532136500"></a><a name="en-us_topic_0167438951_b91532136500"></a>computer_vision/classification/inception_v3</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p113971727161113"><a name="en-us_topic_0167438951_p113971727161113"></a><a name="en-us_topic_0167438951_p113971727161113"></a>For the version description, see the <strong id="en-us_topic_0167438951_b5950192465014"><a name="en-us_topic_0167438951_b5950192465014"></a><a name="en-us_topic_0167438951_b5950192465014"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p83971627131115"><a name="en-us_topic_0167438951_p83971627131115"></a><a name="en-us_topic_0167438951_p83971627131115"></a>For details, see the <strong id="en-us_topic_0167438951_b142001227155012"><a name="en-us_topic_0167438951_b142001227155012"></a><a name="en-us_topic_0167438951_b142001227155012"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b7200192725012"><a name="en-us_topic_0167438951_b7200192725012"></a><a name="en-us_topic_0167438951_b7200192725012"></a>computer_vision/classification/inception_v3</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row17465348111014"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p106251329111119"><a name="en-us_topic_0167438951_p106251329111119"></a><a name="en-us_topic_0167438951_p106251329111119"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b1374716368505"><a name="en-us_topic_0167438951_b1374716368505"></a><a name="en-us_topic_0167438951_b1374716368505"></a>inception_v4.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p1262512901114"><a name="en-us_topic_0167438951_p1262512901114"></a><a name="en-us_topic_0167438951_p1262512901114"></a>This model is used in the <strong id="en-us_topic_0167438951_b5293154116575"><a name="en-us_topic_0167438951_b5293154116575"></a><a name="en-us_topic_0167438951_b5293154116575"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p56252291113"><a name="en-us_topic_0167438951_p56252291113"></a><a name="en-us_topic_0167438951_p56252291113"></a>It is an Inception V4 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p1262552951110"><a name="en-us_topic_0167438951_p1262552951110"></a><a name="en-us_topic_0167438951_p1262552951110"></a>Download the model from the <strong id="en-us_topic_0167438951_b2015335519506"><a name="en-us_topic_0167438951_b2015335519506"></a><a name="en-us_topic_0167438951_b2015335519506"></a>computer_vision/classification/inception_v4</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p15625229171116"><a name="en-us_topic_0167438951_p15625229171116"></a><a name="en-us_topic_0167438951_p15625229171116"></a>For the version description, see the <strong id="en-us_topic_0167438951_b229915613518"><a name="en-us_topic_0167438951_b229915613518"></a><a name="en-us_topic_0167438951_b229915613518"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p862511298110"><a name="en-us_topic_0167438951_p862511298110"></a><a name="en-us_topic_0167438951_p862511298110"></a>For details, see the <strong id="en-us_topic_0167438951_b276711845112"><a name="en-us_topic_0167438951_b276711845112"></a><a name="en-us_topic_0167438951_b276711845112"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b17767138185115"><a name="en-us_topic_0167438951_b17767138185115"></a><a name="en-us_topic_0167438951_b17767138185115"></a>computer_vision/classification/inception_v4</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row979444613104"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p18346631111116"><a name="en-us_topic_0167438951_p18346631111116"></a><a name="en-us_topic_0167438951_p18346631111116"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b583024985111"><a name="en-us_topic_0167438951_b583024985111"></a><a name="en-us_topic_0167438951_b583024985111"></a>mobilenet_v1.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p43461317114"><a name="en-us_topic_0167438951_p43461317114"></a><a name="en-us_topic_0167438951_p43461317114"></a>This model is used in the <strong id="en-us_topic_0167438951_b1235419482571"><a name="en-us_topic_0167438951_b1235419482571"></a><a name="en-us_topic_0167438951_b1235419482571"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p18346831181120"><a name="en-us_topic_0167438951_p18346831181120"></a><a name="en-us_topic_0167438951_p18346831181120"></a>It is a MobileNet V1 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p3346113151116"><a name="en-us_topic_0167438951_p3346113151116"></a><a name="en-us_topic_0167438951_p3346113151116"></a>Download the model from the <strong id="en-us_topic_0167438951_b1354151013551"><a name="en-us_topic_0167438951_b1354151013551"></a><a name="en-us_topic_0167438951_b1354151013551"></a>computer_vision/classification/mobilenet_v1</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p103461831131117"><a name="en-us_topic_0167438951_p103461831131117"></a><a name="en-us_topic_0167438951_p103461831131117"></a>For the version description, see the <strong id="en-us_topic_0167438951_b1424474416557"><a name="en-us_topic_0167438951_b1424474416557"></a><a name="en-us_topic_0167438951_b1424474416557"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p1934773117111"><a name="en-us_topic_0167438951_p1934773117111"></a><a name="en-us_topic_0167438951_p1934773117111"></a>For details, see the <strong id="en-us_topic_0167438951_b1463372117"><a name="en-us_topic_0167438951_b1463372117"></a><a name="en-us_topic_0167438951_b1463372117"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b17633921615"><a name="en-us_topic_0167438951_b17633921615"></a><a name="en-us_topic_0167438951_b17633921615"></a>computer_vision/classification/mobilenet_v1</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row689533810102"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p14326123381113"><a name="en-us_topic_0167438951_p14326123381113"></a><a name="en-us_topic_0167438951_p14326123381113"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b19419162410110"><a name="en-us_topic_0167438951_b19419162410110"></a><a name="en-us_topic_0167438951_b19419162410110"></a>mobilenet_v2.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p632643321113"><a name="en-us_topic_0167438951_p632643321113"></a><a name="en-us_topic_0167438951_p632643321113"></a>This model is used in the <strong id="en-us_topic_0167438951_b1340113554572"><a name="en-us_topic_0167438951_b1340113554572"></a><a name="en-us_topic_0167438951_b1340113554572"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p532623311119"><a name="en-us_topic_0167438951_p532623311119"></a><a name="en-us_topic_0167438951_p532623311119"></a>It is a MobileNet V2 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p6326193381119"><a name="en-us_topic_0167438951_p6326193381119"></a><a name="en-us_topic_0167438951_p6326193381119"></a>Download the model from the <strong id="en-us_topic_0167438951_b1700174515120"><a name="en-us_topic_0167438951_b1700174515120"></a><a name="en-us_topic_0167438951_b1700174515120"></a>computer_vision/classification/mobilenet_v2</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p1832613335112"><a name="en-us_topic_0167438951_p1832613335112"></a><a name="en-us_topic_0167438951_p1832613335112"></a>For the version description, see the <strong id="en-us_topic_0167438951_b174971454814"><a name="en-us_topic_0167438951_b174971454814"></a><a name="en-us_topic_0167438951_b174971454814"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p15327123371110"><a name="en-us_topic_0167438951_p15327123371110"></a><a name="en-us_topic_0167438951_p15327123371110"></a>For details, see the <strong id="en-us_topic_0167438951_b1079413571519"><a name="en-us_topic_0167438951_b1079413571519"></a><a name="en-us_topic_0167438951_b1079413571519"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b1279416579112"><a name="en-us_topic_0167438951_b1279416579112"></a><a name="en-us_topic_0167438951_b1279416579112"></a>computer_vision/classification/mobilenet_v2</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row1814664317105"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p1827573513115"><a name="en-us_topic_0167438951_p1827573513115"></a><a name="en-us_topic_0167438951_p1827573513115"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b164725720214"><a name="en-us_topic_0167438951_b164725720214"></a><a name="en-us_topic_0167438951_b164725720214"></a>resnet18.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p9275113591110"><a name="en-us_topic_0167438951_p9275113591110"></a><a name="en-us_topic_0167438951_p9275113591110"></a>This model is used in the <strong id="en-us_topic_0167438951_b16135627582"><a name="en-us_topic_0167438951_b16135627582"></a><a name="en-us_topic_0167438951_b16135627582"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p1227523513114"><a name="en-us_topic_0167438951_p1227523513114"></a><a name="en-us_topic_0167438951_p1227523513114"></a>It is a ResNet 18 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p5275143510111"><a name="en-us_topic_0167438951_p5275143510111"></a><a name="en-us_topic_0167438951_p5275143510111"></a>Download the model from the <strong id="en-us_topic_0167438951_b5342280219"><a name="en-us_topic_0167438951_b5342280219"></a><a name="en-us_topic_0167438951_b5342280219"></a>computer_vision/classification/resnet18</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p1327533551110"><a name="en-us_topic_0167438951_p1327533551110"></a><a name="en-us_topic_0167438951_p1327533551110"></a>For the version description, see the <strong id="en-us_topic_0167438951_b19113113912210"><a name="en-us_topic_0167438951_b19113113912210"></a><a name="en-us_topic_0167438951_b19113113912210"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p122751235101111"><a name="en-us_topic_0167438951_p122751235101111"></a><a name="en-us_topic_0167438951_p122751235101111"></a>For details, see the <strong id="en-us_topic_0167438951_b2817415213"><a name="en-us_topic_0167438951_b2817415213"></a><a name="en-us_topic_0167438951_b2817415213"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b58115411826"><a name="en-us_topic_0167438951_b58115411826"></a><a name="en-us_topic_0167438951_b58115411826"></a>computer_vision/classification/resnet18</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row441394141015"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p6695133711118"><a name="en-us_topic_0167438951_p6695133711118"></a><a name="en-us_topic_0167438951_p6695133711118"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b4273801214"><a name="en-us_topic_0167438951_b4273801214"></a><a name="en-us_topic_0167438951_b4273801214"></a>resnet50.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p5695163791110"><a name="en-us_topic_0167438951_p5695163791110"></a><a name="en-us_topic_0167438951_p5695163791110"></a>This model is used in the <strong id="en-us_topic_0167438951_b7698118145814"><a name="en-us_topic_0167438951_b7698118145814"></a><a name="en-us_topic_0167438951_b7698118145814"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p66951937161112"><a name="en-us_topic_0167438951_p66951937161112"></a><a name="en-us_topic_0167438951_p66951937161112"></a>It is a ResNet 50 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p18695183720114"><a name="en-us_topic_0167438951_p18695183720114"></a><a name="en-us_topic_0167438951_p18695183720114"></a>Download the model from the <strong id="en-us_topic_0167438951_b19337171417320"><a name="en-us_topic_0167438951_b19337171417320"></a><a name="en-us_topic_0167438951_b19337171417320"></a>computer_vision/classification/resnet50</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p269514376113"><a name="en-us_topic_0167438951_p269514376113"></a><a name="en-us_topic_0167438951_p269514376113"></a>For the version description, see the <strong id="en-us_topic_0167438951_b9947102219315"><a name="en-us_topic_0167438951_b9947102219315"></a><a name="en-us_topic_0167438951_b9947102219315"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p569693714114"><a name="en-us_topic_0167438951_p569693714114"></a><a name="en-us_topic_0167438951_p569693714114"></a>For details, see the <strong id="en-us_topic_0167438951_b02445246315"><a name="en-us_topic_0167438951_b02445246315"></a><a name="en-us_topic_0167438951_b02445246315"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b1024462412310"><a name="en-us_topic_0167438951_b1024462412310"></a><a name="en-us_topic_0167438951_b1024462412310"></a>computer_vision/classification/resnet50</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row37251614782"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p059819395113"><a name="en-us_topic_0167438951_p059819395113"></a><a name="en-us_topic_0167438951_p059819395113"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b755683516315"><a name="en-us_topic_0167438951_b755683516315"></a><a name="en-us_topic_0167438951_b755683516315"></a>resnet101.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p1598123971117"><a name="en-us_topic_0167438951_p1598123971117"></a><a name="en-us_topic_0167438951_p1598123971117"></a>This model is used in the <strong id="en-us_topic_0167438951_b108701158581"><a name="en-us_topic_0167438951_b108701158581"></a><a name="en-us_topic_0167438951_b108701158581"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p9598113981116"><a name="en-us_topic_0167438951_p9598113981116"></a><a name="en-us_topic_0167438951_p9598113981116"></a>It is a ResNet 101 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p1959811392112"><a name="en-us_topic_0167438951_p1959811392112"></a><a name="en-us_topic_0167438951_p1959811392112"></a>Download the model from the <strong id="en-us_topic_0167438951_b2061925214315"><a name="en-us_topic_0167438951_b2061925214315"></a><a name="en-us_topic_0167438951_b2061925214315"></a>computer_vision/classification/resnet101</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p859811399116"><a name="en-us_topic_0167438951_p859811399116"></a><a name="en-us_topic_0167438951_p859811399116"></a>For the version description, see the <strong id="en-us_topic_0167438951_b53121321411"><a name="en-us_topic_0167438951_b53121321411"></a><a name="en-us_topic_0167438951_b53121321411"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p8598163917114"><a name="en-us_topic_0167438951_p8598163917114"></a><a name="en-us_topic_0167438951_p8598163917114"></a>For details, see the <strong id="en-us_topic_0167438951_b443718349415"><a name="en-us_topic_0167438951_b443718349415"></a><a name="en-us_topic_0167438951_b443718349415"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b1243712341941"><a name="en-us_topic_0167438951_b1243712341941"></a><a name="en-us_topic_0167438951_b1243712341941"></a>computer_vision/classification/resnet101</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row3565755811"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p12320164191115"><a name="en-us_topic_0167438951_p12320164191115"></a><a name="en-us_topic_0167438951_p12320164191115"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b15312049849"><a name="en-us_topic_0167438951_b15312049849"></a><a name="en-us_topic_0167438951_b15312049849"></a>resnet152.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p532054151113"><a name="en-us_topic_0167438951_p532054151113"></a><a name="en-us_topic_0167438951_p532054151113"></a>This model is used in the <strong id="en-us_topic_0167438951_b5557152318587"><a name="en-us_topic_0167438951_b5557152318587"></a><a name="en-us_topic_0167438951_b5557152318587"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p2320144171115"><a name="en-us_topic_0167438951_p2320144171115"></a><a name="en-us_topic_0167438951_p2320144171115"></a>It is a ResNet 152 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p183201741111113"><a name="en-us_topic_0167438951_p183201741111113"></a><a name="en-us_topic_0167438951_p183201741111113"></a>Download the model from the <strong id="en-us_topic_0167438951_b7270361259"><a name="en-us_topic_0167438951_b7270361259"></a><a name="en-us_topic_0167438951_b7270361259"></a>computer_vision/classification/resnet152</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p93201541141118"><a name="en-us_topic_0167438951_p93201541141118"></a><a name="en-us_topic_0167438951_p93201541141118"></a>For the version description, see the <strong id="en-us_topic_0167438951_b1431714167518"><a name="en-us_topic_0167438951_b1431714167518"></a><a name="en-us_topic_0167438951_b1431714167518"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p5321144117119"><a name="en-us_topic_0167438951_p5321144117119"></a><a name="en-us_topic_0167438951_p5321144117119"></a>For details, see the <strong id="en-us_topic_0167438951_b20661418957"><a name="en-us_topic_0167438951_b20661418957"></a><a name="en-us_topic_0167438951_b20661418957"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b1566112181558"><a name="en-us_topic_0167438951_b1566112181558"></a><a name="en-us_topic_0167438951_b1566112181558"></a>computer_vision/classification/resnet152</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row696519012818"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p422234301120"><a name="en-us_topic_0167438951_p422234301120"></a><a name="en-us_topic_0167438951_p422234301120"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b1888011352053"><a name="en-us_topic_0167438951_b1888011352053"></a><a name="en-us_topic_0167438951_b1888011352053"></a>vgg16.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p1522374351117"><a name="en-us_topic_0167438951_p1522374351117"></a><a name="en-us_topic_0167438951_p1522374351117"></a>This model is used in the <strong id="en-us_topic_0167438951_b14901930145816"><a name="en-us_topic_0167438951_b14901930145816"></a><a name="en-us_topic_0167438951_b14901930145816"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p16223184310112"><a name="en-us_topic_0167438951_p16223184310112"></a><a name="en-us_topic_0167438951_p16223184310112"></a>It is a VGG16 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p5223184371117"><a name="en-us_topic_0167438951_p5223184371117"></a><a name="en-us_topic_0167438951_p5223184371117"></a>Download the model from the <strong id="en-us_topic_0167438951_b142081647553"><a name="en-us_topic_0167438951_b142081647553"></a><a name="en-us_topic_0167438951_b142081647553"></a>computer_vision/classification/vgg16</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p10223144311117"><a name="en-us_topic_0167438951_p10223144311117"></a><a name="en-us_topic_0167438951_p10223144311117"></a>For the version description, see the <strong id="en-us_topic_0167438951_b3670452061"><a name="en-us_topic_0167438951_b3670452061"></a><a name="en-us_topic_0167438951_b3670452061"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p1422334316113"><a name="en-us_topic_0167438951_p1422334316113"></a><a name="en-us_topic_0167438951_p1422334316113"></a>For details, see the <strong id="en-us_topic_0167438951_b362317549613"><a name="en-us_topic_0167438951_b362317549613"></a><a name="en-us_topic_0167438951_b362317549613"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b106231054066"><a name="en-us_topic_0167438951_b106231054066"></a><a name="en-us_topic_0167438951_b106231054066"></a>computer_vision/classification/vgg16</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row6549133817"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p85381445201113"><a name="en-us_topic_0167438951_p85381445201113"></a><a name="en-us_topic_0167438951_p85381445201113"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b489413612717"><a name="en-us_topic_0167438951_b489413612717"></a><a name="en-us_topic_0167438951_b489413612717"></a>vgg19.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p85381645121115"><a name="en-us_topic_0167438951_p85381645121115"></a><a name="en-us_topic_0167438951_p85381645121115"></a>This model is used in the <strong id="en-us_topic_0167438951_b632311398585"><a name="en-us_topic_0167438951_b632311398585"></a><a name="en-us_topic_0167438951_b632311398585"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p1753844514117"><a name="en-us_topic_0167438951_p1753844514117"></a><a name="en-us_topic_0167438951_p1753844514117"></a>It is a VGG19 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p553813451112"><a name="en-us_topic_0167438951_p553813451112"></a><a name="en-us_topic_0167438951_p553813451112"></a>Download the model from the <strong id="en-us_topic_0167438951_b956619221872"><a name="en-us_topic_0167438951_b956619221872"></a><a name="en-us_topic_0167438951_b956619221872"></a>computer_vision/classification/vgg19</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p053894518111"><a name="en-us_topic_0167438951_p053894518111"></a><a name="en-us_topic_0167438951_p053894518111"></a>For the version description, see the <strong id="en-us_topic_0167438951_b91766311677"><a name="en-us_topic_0167438951_b91766311677"></a><a name="en-us_topic_0167438951_b91766311677"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p1253854581112"><a name="en-us_topic_0167438951_p1253854581112"></a><a name="en-us_topic_0167438951_p1253854581112"></a>For details, see the <strong id="en-us_topic_0167438951_b1756683212718"><a name="en-us_topic_0167438951_b1756683212718"></a><a name="en-us_topic_0167438951_b1756683212718"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b115661432573"><a name="en-us_topic_0167438951_b115661432573"></a><a name="en-us_topic_0167438951_b115661432573"></a>computer_vision/classification/vgg19</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row33092581075"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p265315476115"><a name="en-us_topic_0167438951_p265315476115"></a><a name="en-us_topic_0167438951_p265315476115"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b18630361478"><a name="en-us_topic_0167438951_b18630361478"></a><a name="en-us_topic_0167438951_b18630361478"></a>squeezenet.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p17653194714118"><a name="en-us_topic_0167438951_p17653194714118"></a><a name="en-us_topic_0167438951_p17653194714118"></a>This model is used in the <strong id="en-us_topic_0167438951_b1211254714582"><a name="en-us_topic_0167438951_b1211254714582"></a><a name="en-us_topic_0167438951_b1211254714582"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p6653194718113"><a name="en-us_topic_0167438951_p6653194718113"></a><a name="en-us_topic_0167438951_p6653194718113"></a>It is a SqueezeNet model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p3653184712114"><a name="en-us_topic_0167438951_p3653184712114"></a><a name="en-us_topic_0167438951_p3653184712114"></a>Download the model from the <strong id="en-us_topic_0167438951_b13113957373"><a name="en-us_topic_0167438951_b13113957373"></a><a name="en-us_topic_0167438951_b13113957373"></a>computer_vision/classification/squeezenet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p1065384718113"><a name="en-us_topic_0167438951_p1065384718113"></a><a name="en-us_topic_0167438951_p1065384718113"></a>For the version description, see the <strong id="en-us_topic_0167438951_b844671217815"><a name="en-us_topic_0167438951_b844671217815"></a><a name="en-us_topic_0167438951_b844671217815"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p86531547121116"><a name="en-us_topic_0167438951_p86531547121116"></a><a name="en-us_topic_0167438951_p86531547121116"></a>For details, see the <strong id="en-us_topic_0167438951_b16884114181"><a name="en-us_topic_0167438951_b16884114181"></a><a name="en-us_topic_0167438951_b16884114181"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b88843146810"><a name="en-us_topic_0167438951_b88843146810"></a><a name="en-us_topic_0167438951_b88843146810"></a>computer_vision/classification/squeezenet</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p1315674402311"><a name="en-us_topic_0167438951_p1315674402311"></a><a name="en-us_topic_0167438951_p1315674402311"></a><strong id="en-us_topic_0167438951_b41567442232"><a name="en-us_topic_0167438951_b41567442232"></a><a name="en-us_topic_0167438951_b41567442232"></a>Precautions during model conversion:</strong></p>
    <p id="en-us_topic_0167438951_p8156174452317"><a name="en-us_topic_0167438951_p8156174452317"></a><a name="en-us_topic_0167438951_p8156174452317"></a>The classification application processes one picture at a time. Therefore, the value of N in <strong id="en-us_topic_0167438951_b111571944132312"><a name="en-us_topic_0167438951_b111571944132312"></a><a name="en-us_topic_0167438951_b111571944132312"></a>Input Shaple</strong> needs to be changed to 1 during conversion, as shown in <a href="#en-us_topic_0167438951_fig20240124719920">Figure 1</a>.</p>
    </td>
    </tr>
    <tr id="en-us_topic_0167438951_row2011118432011"><td class="cellrowborder" valign="top" width="15.841584158415841%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0167438951_p8807195615216"><a name="en-us_topic_0167438951_p8807195615216"></a><a name="en-us_topic_0167438951_p8807195615216"></a>Image classification inference model (<strong id="en-us_topic_0167438951_b83371334483"><a name="en-us_topic_0167438951_b83371334483"></a><a name="en-us_topic_0167438951_b83371334483"></a>dpn98.om</strong>)</p>
    </td>
    <td class="cellrowborder" valign="top" width="21.782178217821784%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0167438951_p158071856152116"><a name="en-us_topic_0167438951_p158071856152116"></a><a name="en-us_topic_0167438951_p158071856152116"></a>This model is used in the <strong id="en-us_topic_0167438951_b0675813175912"><a name="en-us_topic_0167438951_b0675813175912"></a><a name="en-us_topic_0167438951_b0675813175912"></a>classification</strong> application.</p>
    <p id="en-us_topic_0167438951_p1580725614215"><a name="en-us_topic_0167438951_p1580725614215"></a><a name="en-us_topic_0167438951_p1580725614215"></a>It is a DPN-98 model based on Caffe.</p>
    </td>
    <td class="cellrowborder" valign="top" width="28.71287128712871%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0167438951_p10808195622117"><a name="en-us_topic_0167438951_p10808195622117"></a><a name="en-us_topic_0167438951_p10808195622117"></a>Download the model from the <strong id="en-us_topic_0167438951_b363416111910"><a name="en-us_topic_0167438951_b363416111910"></a><a name="en-us_topic_0167438951_b363416111910"></a>computer_vision/classification/dpn98</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    <p id="en-us_topic_0167438951_p3808175642119"><a name="en-us_topic_0167438951_p3808175642119"></a><a name="en-us_topic_0167438951_p3808175642119"></a>For the version description, see the <strong id="en-us_topic_0167438951_b2437151811913"><a name="en-us_topic_0167438951_b2437151811913"></a><a name="en-us_topic_0167438951_b2437151811913"></a>README.md</strong> file in the current directory.</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.663366336633665%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0167438951_p1280835672115"><a name="en-us_topic_0167438951_p1280835672115"></a><a name="en-us_topic_0167438951_p1280835672115"></a>For details, see the <strong id="en-us_topic_0167438951_b20234152018917"><a name="en-us_topic_0167438951_b20234152018917"></a><a name="en-us_topic_0167438951_b20234152018917"></a>README.md</strong> file of the <strong id="en-us_topic_0167438951_b132341820291"><a name="en-us_topic_0167438951_b132341820291"></a><a name="en-us_topic_0167438951_b132341820291"></a>computer_vision/classification/dpn98</strong> directory in the <a href="https://github.com/Ascend/models/" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/models/</a> repository.</p>
    </td>
    </tr>
    </tbody>
    </table>

    **Figure  1**  Configuration for the classification model during conversion<a name="en-us_topic_0167438951_fig20240124719920"></a>  
    ![](doc/source/img/configuration-for-the-network-connectivity-model-during-conversion.png "configuration-for-the-network-connectivity-model-during-conversion")

    The classification application processes one picture each time. Therefore, the value of batch needs to be changed to 1 during model conversion.

-   Download the dependent software library
     
     Download the dependent software libraries to the **sample-classification/script** directory.

    **Table  2**  Download the dependent software library

    <a name="en-us_topic_0167438951_table141761431143110"></a>
    <table><thead align="left"><tr id="en-us_topic_0167438951_row18177103183119"><th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.1"><p id="en-us_topic_0167438951_p8177331103112"><a name="en-us_topic_0167438951_p8177331103112"></a><a name="en-us_topic_0167438951_p8177331103112"></a>Module Name</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.2"><p id="en-us_topic_0167438951_p1317753119313"><a name="en-us_topic_0167438951_p1317753119313"></a><a name="en-us_topic_0167438951_p1317753119313"></a>Module Description</p>
    </th>
    <th class="cellrowborder" valign="top" width="33.33333333333333%" id="mcps1.2.4.1.3"><p id="en-us_topic_0167438951_p1417713111311"><a name="en-us_topic_0167438951_p1417713111311"></a><a name="en-us_topic_0167438951_p1417713111311"></a>Download Address</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0167438951_row19177133163116"><td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0167438951_p2017743119318"><a name="en-us_topic_0167438951_p2017743119318"></a><a name="en-us_topic_0167438951_p2017743119318"></a>EZDVPP</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0167438951_p52110611584"><a name="en-us_topic_0167438951_p52110611584"></a><a name="en-us_topic_0167438951_p52110611584"></a>Encapsulates the dvpp interface and provides image and video processing capabilities, such as color gamut conversion and image / video conversion</p>
    </td>
    <td class="cellrowborder" valign="top" width="33.33333333333333%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0167438951_p31774315318"><a name="en-us_topic_0167438951_p31774315318"></a><a name="en-us_topic_0167438951_p31774315318"></a><a href="https://github.com/Ascend/sdk-ezdvpp" target="_blank" rel="noopener noreferrer">https://github.com/Ascend/sdk-ezdvpp</a></p>
    <p id="en-us_topic_0167438951_p1634523015710"><a name="en-us_topic_0167438951_p1634523015710"></a><a name="en-us_topic_0167438951_p1634523015710"></a>After the download, keep the folder name <span class="filepath" id="en-us_topic_0167438951_filepath1324864613582"><a name="en-us_topic_0167438951_filepath1324864613582"></a><a name="en-us_topic_0167438951_filepath1324864613582"></a><b>ezdvpp</b></span>。</p>
    </td>
    </tr>
    </tbody>
    </table>


