# 算法解释
双指针主要用于遍历数组，两个指针指向不同的元素，从而协同完成任务。也可以延伸到多
个数组的多个指针。
若两个指针指向同一数组，遍历方向相同且不会相交，则也称为滑动窗口（两个指针包围的
区域即为当前的窗口），经常用于区间搜索。
若两个指针指向同一数组，但是遍历方向相反，则可以用来进行搜索，待搜索的数组往往是
排好序的。
对于 C++ 语言，指针还可以玩出很多新的花样。一些常见的关于指针的操作如下。

指针与常量
```c++
int x;
int * p1 = &x; // 指针可以被修改，值也可以被修改
const int * p2 = &x; // 指针可以被修改，值不可以被修改（const int）
int * const p3 = &x; // 指针不可以被修改（* const），值可以被修改
const int * const p4 = &x; // 指针不可以被修改，值也不可以被修改
```
指针函数与函数指针
```c++
// addition是指针函数，一个返回类型是指针的函数
int* addition(int a, int b) {
    int* sum = new int(a + b);
    return sum;
}
int subtraction(int a, int b) {
    return a - b;
}
int operation(int x, int y, int (*func)(int, int)) {//定义接收函数指针的值的形式：int (*func)(int, int)
    return (*func)(x,y);//将得到的函数指针值表示为函数，前面加*
}
// minus是指向subtraction()函数的指针,minus表示指针的值，*minus表示该值指向的subtraction()函数
int (*minus)(int, int) = subtraction;
int* m = addition(1, 2);
int n = operation(3, *m, minus);//这里传递的是subtraction()函数的指针的值，而不是函数本身
```