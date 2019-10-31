#!/bin/bash
script_path="$( cd "$(dirname "$0")" ; pwd -P )"


function main()
{
    count=0
    for om_name in $(find ${script_path}/model/ -name "*.om");do
	let count++
	if [ count -ge 1 ];then
	    break
	fi
    done
    if [ count -eq 0 ];then
        echo "please push your model file in sample_classification/src/model "
        return 1
    fi
    om_name=$(basename ${om_name})
    cp ${script_path}/graph.template ${script_path}/graph.config
    sed -i "s#\${MODEL_PATH}#../../src/model/${om_name}#g"  ${script_path}/graph.config
    if [ $? != 0 ];then
	echo "gengrate graph.config error !"
	return 1
    fi 
    return 0	
}
main

