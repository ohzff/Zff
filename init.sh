echo " Welcome to use LanGong Zff Game!"
echo "   GitHub Repo: https://github.com/ohzff/Zff"
echo " >> Creating user"
mkdir ~/.local/share/ohzff-zff
echo $USER > ~/.local/share/ohzff-zff/user
echo 1 > ~/.local/share/ohzff-zff/boot
echo 0 > ~/.local/share/ohzff-zff/level
echo " >> Created user successfully!"
echo " Input 'zff' in user '$USER' to run the game with this user."

