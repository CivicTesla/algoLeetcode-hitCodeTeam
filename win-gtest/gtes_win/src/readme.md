# 项目
src/的.cpp文件是项目文件，程序员可通过引用src/include下的h头文件，来引用自定义函数
自定义函数：src/include存放头文件，供外部引用,src/src存放着src/include中各头文件的具体实现
# gtest测试
test文件夹即gtest项目，可用于测试项目文件夹src/src里面的函数；
具体操作见test目录下的CMakeList文件