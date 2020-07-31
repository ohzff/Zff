# Zff

![GitHub release (latest by date)](https://img.shields.io/github/v/release/langong-dev/Zff?logo=Github)
![GitHub repo size](https://img.shields.io/github/repo-size/langong-dev/Zff)
![GitHub top language](https://img.shields.io/github/languages/top/langong-dev/Zff)

# Run in 运行于

- [ ] [Microsofts Windows (Click to Windows)](https://github.com/langong-dev/Zff-Win.git)
  - None 均不可用
- [x] Linux
  - All 全可用
- [x] MacOS

# Install 安装

## By AUR (ArchLinux) 通过aur安装

```bash
$ yaourt -S zff  ## you can also use other app, like yay, pacaur...
```

## By npm

```bash
# npm install -g langong-zff
# bash zffinit
```

## By dkpg (Debian, Ubuntu) 通过dkpg安装

Download `zff-deb.deb` from releases page.

从下载（releases）页面下载 `zff-deb.deb`。

```bash
# dkpg -i zff-deb.deb
```

## Others 其他

```bash
$ git clone https://github.com/ohzff/Zff
$ cd Zff
# bash install.sh
```

# Add user 添加用户

```bash
$ zff init
```

# Run 运行

```bash
$ zff
```

# Update 更新（手动）

## DEB and Other

```bash
$ cd /usr/share/ohzff-zff
# git pull
# g++ zff_main_en.cpp -o /usr/bin/zff
```

## npm

```bash
$ cd /usr/lib/node_modules/langong-zff
# git pull
# g++ zff_main_en.cpp -o zff
```

## Aur users

```bash
yaourt -Syu
```

# Chang mod(branch) 切换模式

We have these two mod/branch.

- `master` : Default mod 默认模式
- `dev` : Develope mod 开发者模式（测试版）

> We don't know if dev branch will damage your computer. So please you think a lot about this before change the branch.
> 
> 我们不知道dev分支是否会伤害您的电脑，所以请您慎重考虑后在切换分支。

```bash
    ## AUR, DEB, Other
$ cd /usr/share/ohzff-zff
    ## npm
$ cd /usr/lib/node_modules/langong-zff

# git pull
# git checkout dev
    ## If you want to change to master, you can input '...checkout master'

    ## AUR, DEB, Other
# g++ zff_main_en.cpp -o /usr/bin/zff
    ## npm
# g++ zff_main_en.cpp -o zff
```

Then, you can restart the game.

# Feedback 反馈

Issues

# Author 作者

- @langonginc Main author and yarn/npm publisher 主要作者，yarn/npm发布者
- @Arch-Jason AUR, DEB publisher AUR,DEB发布者
