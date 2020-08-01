echo " LanGong Zff Game login"
echo "   You can sign it on zff.516wjy.xyz"
echo -n " username:  "
read user
echo -n " password:  "
read pass

md5pass="$(echo -n $pass|md5sum|cut -d ' ' -f1)"

echo " User $user, Password in md5 '$md5pass'"

