#/bin/bash
#      FileName: build.sh
# 
#        Author: 
#   Description: ---
#  Created Time: 2019年06月30日 星期日 14时48分56秒
# Last Modified: 2019-06-30 14:48:56
# 
#!/bin/bash

BUILD=`pwd`
#echo "${BUILD}"
cd ${BUILD}/build

cmake .. && make


