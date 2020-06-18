#!/bin/bash

echo " Welcome to LanGong Zff Game for Linux."
sleep 0.5

g++ zff_main_ch.cpp -o zff-ch && g++ zff_main_en.cpp -o zff-en && g++ start.cpp -o zff
echo " >> Please set a UserName 请设定一个用户名";
read name;
echo $name >> user.dll
rm -f boot.dll
rm -f level.dll
echo 1 >> boot.dll
echo 0 >> level.dll

echo " >> Install successfully!"
echo 
echo " >> You can input './zff' to start game! Enjoy~"

