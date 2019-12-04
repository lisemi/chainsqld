# Ubuntu 编译
## 系统需求
- 建议 Ubutun 16.04 及以上版本

## 安装工具
-  git 
- cmake

## 下载源码
- git clone git@github.com:ChainSQL/zhshchaind.git zhshchaind

## 安装开发环境依赖
- 进入编译目录
```bash
> cd Builds/Ubuntu
```
- 分别执行下面指令
```bash
> sudo ./install_rippled_depends_ubuntu.sh
> ./install_boost.sh
```
- 在 ~/.bashrc 文件中保存 BOOST_ROOT 环境变量

```bash
export BOOST_ROOT=/home/dbliu/work/zhshchain/Builds/Ubuntu/boost_1_63_0
```
- 让 BOOST_ROOT 环境变量生效
```bash
> source ~/.bashrc
```

## 编译 zhshchaind
- 重新进入源码根目录
```bash
> cd ~/work/zhshchaind
```
- 创建并进入编译目录 build
```bash
> mkdir build && cd build
```
- 执行 cmake
```bash
> cmake -Dtarget=gcc.debug.nounity|gcc.debug.unity|gcc.release.nounity|gcc.release.unity ..
```

> 或

```bash
> cmake -DCMAKE_BUILD_TYPE=Release|Debug ..
```

- 编译

```base
> make zhshchaind -j2
```
