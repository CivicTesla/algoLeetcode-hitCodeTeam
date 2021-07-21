
#include <vector>
#include "../include/breaknine/print.h"
int main()
{
    int i = 1;
    // 整数
    printf("%d\n", i);
    // 整数
    print(i);
    // 数组
    int list[] = {1,2,3,4,5,6};
    print(list,sizeof(list)/sizeof(list[0]));
    // 数组vector
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(vec);
}
