[[_TOC_]]

# 介绍
一个用来练习打代码的repository
```
hi
HitCode 即打码
```
## tip：
#### 第三方包的简单使用
- 仓库根目录的include/文件夹用于存放一些自定义包，第三方库等，可供便捷地调用
```c++
//引用即可使用，比如仿gtest框架，自定义的程序运行时间测试，文件位于：第三方包简单使用/timeTest.cpp，代码如下：
#include "include/test/timeTest.h"
```
#### gtest
- win-gtest文件夹：win下，gtest的使用示范
#### mocha
js单元测试工具
https://github.com/yefan2018/mocha-demos
说明文件：http://www.ruanyifeng.com/blog/2015/12/a-mocha-tutorial-of-examples.html
#### chai
include\test\chai.js
断言库有很多种，Mocha并不限制使用哪一种。
#### junit
java单元测试工具
#### 其他文件说明
- js使用node管理第三方包；package.json的dependencies和devDependencies用于记录所有的包，框架，其他语言手动输入
- py使用conda或pip管理第三方包，记录requirements.txt，便捷安装命令：
```bash
pip3 install -r requirements.txt 或 
conda install -r requirements.txt
```
- java包工具mavan的vscode教程：https://www.bilibili.com/video/av62014282
## 算法笔记
