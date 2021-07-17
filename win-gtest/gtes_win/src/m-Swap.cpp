//t 注意cpp文件如果与所引用的.h(.cpp)文件重名，cmake -G "MinGW Makefiles" .. 时可能不会将其列入make队列，例如这里命名为swap，或swap1将可能不被make编译。

#include <iostream>

#include "math/swap.h"

using namespace std;

int main(int argc, char **argv) {
    int val1 = 10;
    int val2 = 20;
    cout << "before swap: val1=" << val1 << ", val2=" << val2 << endl;
    swap(val1, val2);
    cout << "after swap: val1=" << val1 << ", val2=" << val2 << endl;
    return 0;
}
