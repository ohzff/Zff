#/bin/bash

echo " OhZff Zff Install Script"
echo ' >> Install Zff...'
echo '    -> (0/3) Prepare...'
mkdir -p ~/.tmp-zff
mkdir -p /usr/share/ohzff-zff
cd ~/.tmp-zff

echo '    -> (1/4) Clone repo from GitHub:ohzff/Zff...'
git clone https://github.com/ohzff/Zff.git
cd Zff

echo '    -> (2/4) Compiling...'
g++ ./zff_main_en.cpp -o zff

echo '    -> (3/4) Coping files...'
cp ./zff /usr/bin/zff
cp -r ./* /usr/share/ohzff-zff/

echo '    -> (4/4) This step have done.'
echo ' >> Check Install'
echo '    -> (0/1) Check files...'
isok=0
if [ ! -f /usr/bin/zff ]; then
  isok=1
  echo '       Warning: zff is not found!'
fi
if [ ! -d /usr/share/ohzff-zff ]; then
  isok=1
  echo '       Warning: ohzff-zff is not found!'
fi

echo '    -> (1/1) Checked.'

if [ $isok == 0 ]; then
  echo ' >> Installed Ohzff Zff.'
else
  echo ' >> Install Ohzff Zff failed, returned value 1.'
  exit 1
fi

