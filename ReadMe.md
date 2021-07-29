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

1.0.1 print.h

```c++
 #include "../../include/breaknine/print.h" 
//  ------print------
//  输出整数
 print(i)
//  输出数组，要输入数组的个数
 print(list,sizeof(list)/sizeof(list[1]));
//  输出vector数组
 printv(vec)
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
// 输出数组 int l[]
n=sizeof(l)/sizeof(l[0]);//l以传址方式传入print，在print内使用sizeof(l)会失效，因此在print外部把数组元素个数传进去
print(l,n)
```
### 1.2 gtest
- google测试框架，位于win-gtest文件夹

### <font color=00FFFF>1.3 O()|O()</font>

<p>数据量越大，需要耗时越多，但是不同时间复杂度随数据量增长的速度是不一样的。有的算法对数据量增长比较敏感，数据量增长一点就会增加非常多的运算次数；有的算法对数据量增长不敏感，运行时间和数据规模呈线性关系。比 <img src="https://www.zhihu.com/equation?tex=O%28n%5E3+%29" alt="[公式]" eeimg="1" data-formula="">O(n^3 ) 还大的算法复杂度包括 <img src="https://www.zhihu.com/equation?tex=O%282%5En%29" alt="[公式]" eeimg="1" data-formula=""> O(2^n)和 <img src="https://www.zhihu.com/equation?tex=O%28n%21%29" alt="[公式]" eeimg="1" data-formula="">O(n!) ，即使 <img src="https://www.zhihu.com/equation?tex=n+" alt="[公式]" eeimg="1" data-formula=" ">n 只有几十，其运算次数也是天文数字，这就是很多搜索回溯算法不能处理稍大规模数据的原因。log(n)最不敏感</p>

<img src="readmePic\timeSpace.jpg" width=50% >











# <font color=grer>2.算法笔记:</font>

2. 1 位运算符速查:
   位运算符作用于位，并逐位执行操作。&、 | 和 ^ 的真值表如下所示：

| p       | q        |  p&q  | p\|q  | p^q   |
|:-------:|:--------:| -----:| -----:| -----:|
| 0       | 0        | 0     | 0     | 0     |
| 0       | 1        | 0     | 1     | 1     |
| 1       | 1        | 1     | 1     | 0     |
| 1       | 0        | 0     | 1     | 1     |

-----------------
假设如果 A = 60，且 B = 13，现在以二进制格式表示，它们如下所示：

A = 0011 1100

B = 0000 1101



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



   2.2 对象指针化
将一般对象改为指针形式，对象的属性要用->来指定

   2.3 ::
C::member，双冒号表示类C里面的成员（属性，函数）

# <font color=red>3.算法疑问收集:</font>
- 7.2/70ClimbingStairsEasy.cpp
？输入48到148左右的数，输出结果为负数
