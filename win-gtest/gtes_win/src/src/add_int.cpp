#include "math/add_int.h"

//* inline,内联函数：提高运行效率。定义内联函数的方法很简单，只要在函数定义的头前加上关键字inline即可;在程序中，调用其函数时，该函数在编译时被替代，而不是像一般函数那样是在运行时被调用。
//t 内联函数在.h文件中定义，mingw32-make时可能出错，不过不影响输出可执行文件
int add_int (int a, int b) {
    return a+b;
    }
