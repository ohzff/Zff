#/bin/bash

echo ' LanGong OhZff Zff Uninstall Script.'
echo ' >> Uninstall'
echo '    -> (0/2) Uninstall Exec...'
rm /usr/bin/zff || echo '       -> Warnning: Cannot Uninstall it!'
echo '    -> (1/2) Uninstall All files...'
rm -r /usr/share/ohzff-zff || echo '       -> Warnning: Cannot Uninstall it!'
echo '    -> (2/2) This step have done.'

echo ' >> Check Uninstall'
isdel=0
echo '    -> (0/2) Checking Exec...'
if [ -f "/usr/bin/zff" ]
then
  echo '       -> Warnning: /usr/bin/zff has not uninstalled!'
  isdel=1
fi
echo '    -> (1/2) Checking All Files...'
if [ -d "/usr/share/ohzff-zff" ]
then
  echo '       -> Warnning: /usr/share/ohzff-zff has not uninstalled!'
  isdel=1
fi
echo '    -> (2/2) This step have done.'
echo ' >> Check Return value'
echo '    -> (0/1) Checking return value...'
if [ $isdel == 0 ]; then
  echo '    -> (1/1) This step have done.'
  echo ' >> Uninstalled LanGong OhZff Zff.'
else
  echo '       -> Failed: Files are not uninstalled.'
  echo '    -> (1/1) This step have done with BAD VALUE.'
  echo ' >> Uninstalled failed!'
  exit 1
fi
