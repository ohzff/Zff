# Usage 使用

## Add user 添加用户

```bash
$ zff init
```

## Run 运行

```bash
$ zff
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

