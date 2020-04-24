#!/bin/bash

echo " Please set a UserName 请设定一个用户名";
read name;
echo $name >> user.dll
rm -f boot.dll
rm -f level.dll
echo 1 >> boot.dll
echo 0 >> level.dll
