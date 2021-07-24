[[_TOC_]]

# <font color=#ffcc33>0.介绍:</font>
一个用来练习打代码的repository
```
hi
HitCode 即打码
```
***
# <font color=grere>1.tip：</font>
### 1.0 第三方包的简单使用
 仓库根目录的include/文件夹用于存放一些自定义包，第三方库等，可供便捷地调用:
    1.0.0 仿gtest框架，自定义的程序运行时间测试。```#include "include/test/timeTest.h"```
    1.0.1 print.h，简化输出，引入后，使用print(变量)即可输出，支持int，int []，vector数组。
```c++
 #include "../../include/breaknine/print.h" 
//  ------print------
//  输出整数
 print(i)
//  输出数组，要输入数组的个数
 print(list,sizeof(list)/sizeof(list[1]));
//  输出vector数组
 print(vec)
//  输出字符串 string
    string input =  "2-1-1";
    print(input)
    // 字符串切片，左开右闭区间
    print(input.substr(0,5));
// 输出进制数
print2(15);//2代表2进制，15是10进制数；目前支持2，8，10，16；
//  c++ ------printf------
int a = 1;
printf("%d\n",i);
// 输出浮点数
printf("%f/n",1.2);
// 输出单个字符 char类型
string input =  "2-1-1";
char c0 = "2"[0];
char c = input[0];
printf("%c",c);
 ```
### 1.1 gtest
- google测试框架，位于win-gtest文件夹

### 1.2 其他文件说明
- package.json用于记录所用的包，框架；
- .gitkeep 无用文件，只为向git证明该文件夹存在
- codeblocks_debug,codeblocks编辑器debug
***
# <font color=grer>2.算法笔记:</font>

2.1 创建n维数组：
```c++
//* 2.1.1构造一维数组vec
int ele[] = {2,7,11,15};
vector<int> vec0(ele, ele+sizeof(ele)/sizeof(int));//sizeof(ele)用于统计int ele[]所有元素的字节数，sizeof(int)表示单个int类型所占字节数，两者相除即ele[]中元素的个数
// 简约写法
vector<int> vec1{2,7,11,15};

//* 2.1.2构造二维数组
int element0[] = {1,0,1,1,0,1,0,1};
vector<int> vec0(element0, element0+sizeof(element0)/sizeof(int));
int element1[] = {1,0,1,1,0,1,1,1};
vector<int> vec1(element1, element1+sizeof(element1)/sizeof(int));
int element2[] = {0,0,0,0,0,0,0,1};
vector<int> vec2(element2, element2+sizeof(element2)/sizeof(int));

vector<int> ele[] = {vec0,vec1,vec2};
vector<vector<int>> vec(ele,ele+sizeof(ele)/sizeof(vector<int>));
// 简约写法
vector<vector<int>> vec{{1,0,1,1,0,1,0,1},{1,0,1,1,0,1,1,1},{0,0,0,0,0,0,0,1}};
```
2.2 输出数组vec：
C++的cout输出不了vector<>类型数组，因此用下面的方法输出
```c++
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
输出int []类型数组
```c++
// 输出数组 int l[]
n=sizeof(l)/sizeof(l[0]);//l以传址方式传入print，在print内使用sizeof(l)会失效，因此在print外部把数组元素个数传进去
print(l,n)
```
2.3 break的用法：
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
2.4 位运算符:
位运算符作用于位，并逐位执行操作。&、 | 和 ^ 的真值表如下所示：

| p       | q        |  p&q  | p\|q  | p^q   |
| ------- |:--------:| -----:| -----:| -----:|
| 0       | 0        | 0     | 0     | 0     |
| 0       | 1        | 0     | 1     | 1     |
| 1       | 1        | 1     | 1     | 0     |
| 1       | 0        | 0     | 1     | 1     |
假设如果 A = 60，且 B = 13，现在以二进制格式表示，它们如下所示：

A = 0011 1100

B = 0000 1101

-----------------

A&B = 0000 1100

A|B = 0011 1101

A^B = 0011 0001

~A  = 1100 0011

下表显示了 C++ 支持的位运算符。假设变量 A 的值为 60，变量 B 的值为 13，则：

|运算符|描述|	实例|
|--|:--:|--:|
|&	|如果同时存在于两个操作数中，二进制 AND 运算符复制一位到结果中。|	(A & B) 将得到 12，即为 0000 1100|
|\|	|如果存在于任一操作数中，二进制 OR 运算符复制一位到结果中。	|(A | B) 将得到 61，即为 0011 1101|
|^	|如果存在于其中一个操作数中但不同时存在于两个操作数中，二进制异或运算符复制一位到结果中。	|(A ^ B) 将得到 49，即为 0011 0001|
|~	|二进制补码运算符是一元运算符，具有"翻转"位效果，即0变成1，1变成0。|	(~A ) 将得到 -61，即为 1100 0011，一个有符号二进制数的补码形式。|
|<<	|二进制左移运算符。左操作数的值向左移动右操作数指定的位数。	|A << 2 将得到 240，即为 1111 0000|
|>>	|二进制右移运算符。左操作数的值向右移动右操作数指定的位数。	|A >> 2 将得到 15，即为 0000 1111|

2.5 对象指针化
将一般对象改为指针形式，对象的属性要用->来指定
# <font color=red>3.算法疑问收集:</font>
- 7.2/70ClimbingStairsEasy.cpp
？输入48到148左右的数，输出结果为负数