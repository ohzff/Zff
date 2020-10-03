# Usage 使用

`zff [OPTION]` or `./zff [OPTIONS]`.

> use `zff` when you installed OhZff zff.
>
> use `./zff` when you didn't install OhZff or you cannot install OhZff Zff.

## Init 初始化

```cpp
$ zff init
```

## Run 运行

```cpp
$ zff
```

## View License 查看版权信息

```cpp
$ zff license
```

# Chang mod(branch) 切换模式

We have these two mod/branch.

- `master` : Default mod 默认模式
- `dev` : Develope mod 开发者模式（测试版）

> We don't know if dev branch will damage your computer. So please you think a lot about this before change the branch.
> 
> 我们不知道dev分支是否会伤害您的电脑，所以请您慎重考虑后在切换分支。

```cpp
$ cd /usr/share/ohzff-zff

# git pull
# git checkout dev
    ## If you want to change to master, you can input '...checkout master'

# g++ zff_main_en.cpp -o /usr/bin/zff
```

Then, you can restart the game.

