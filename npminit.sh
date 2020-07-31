echo " >> Wait"

ln -sf /usr/lib/node_modules/langong-zff /usr/share/ohzff-zff || echo "ERROR: you can use root user and try again" 
g++ /usr/share/ohzff-zff/zff_main_en.cpp -o /usr/lib/node_modules/langong-zff/zff || echo "ERROR: Unkonw error" 

echo " >> Installed"


