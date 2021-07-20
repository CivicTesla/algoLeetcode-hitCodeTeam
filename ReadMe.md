[[_TOC_]]

# 介绍
一个用来练习打代码的repository
```
hi
HitCode 即打码
```

## tip：
### 第三方包的简单使用
- 仓库根目录的include/文件夹用于存放一些自定义包，第三方库等，可供便捷地调用
```c++
//引用即可使用，比如仿gtest框架，自定义的程序运行时间测试，文件位于：第三方包简单使用/timeTest.cpp，代码如下：
#include "include/test/timeTest.h"
```
### gtest
- win-gtest文件夹：win下，gtest的使用示范

### 其他文件说明
- package.json用于记录所用的包，框架；

***
## 算法笔记
C++的cout输出不了vector<>类型数组，因此用下面的方法输出
```c++
// 构造数组vec
int ele[] = {2,7,11,15};
vector<int> vec0(ele, ele+sizeof(ele)/sizeof(int));//sizeof(ele)用于统计int ele[]所有元素的字节数，sizeof(int)表示单个int类型所占字节数，两者相除即ele[]中元素的个数
// 简约写法
vector<int> vec1{2,7,11,15};

// 输出数组vec
// * ----------------------显示数组
    vector<int> vec =  vec0;
    vector<int>::iterator ite = vec.begin();
	for (; ite != vec.end(); ite++){
		cout << *ite;
		cout << ",";
	}
    cout << endl;// * ----------------------显示数组结束
```

break的用法：
當滿足中斷條件時，就離開迴圈( while 或 for )
```c++
while / for( ... )
{
    ...
    if( 中斷條件 )
    {
        break;
    }
    ...
}
```