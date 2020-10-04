# Install 安装

## Your system 查看你的系统适合那个

- AUR : ArchLinux, ArcoLinux, ManjaroLinux
- dpkg : DebianLinux, UbuntuLinux
- Others : Any-Linux, MacOS

## By AUR (ArchLinux) 通过aur安装

```cpp
$ yaourt -S zff  ## you can also use other app, like yay, pacaur...
```

## By dpkg (Debian, Ubuntu) 通过dpkg安装

Download `zff-*.deb` from releases page.

从下载（releases）页面下载 `zff-*.deb`。

```cpp
# dpkg -i zff-deb.deb
```

## Others (Linux, MacOS) 其他

```cpp
# bash $(curl http://cdn.jsdelivr.net/gh/ohzff/zff/atinstall.sh)
```
