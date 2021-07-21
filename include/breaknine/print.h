#ifndef __PRINT_H_
#define __PRINT_H_

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


int printn(int num)
{
    cout << num << endl;
    return 0;
};

void printl(int list[],int n)//!! 数组作为复杂类型数据，以传地址方式传入函数，sizeof()函数失效，无法统计数组所占字节数
{
    int i;
    for (int i = 0; i < n; i++){
        cout << list[i];
        if (i < n-1){
            cout << ",";
        }
    }
    cout << endl;
};
int printv(vector<int> vec)
{
    // * ----------------------显示数组
    vector<int>::iterator ite = vec.begin();
    for (; ite != vec.end(); ite++)
    {
        cout << *ite;
        if (ite < vec.end()-1 ){
            cout << ",";
        }
    }
    cout << endl; // * ----------------------显示数组结束
    return 0;
}

// t 同名函数，不同类型形参，在调用print的时候，编译器设定：会自动根据变量类型寻找该接收的函数
void print(int variable){
    printn(variable);
}
void print(int list[],int n) {
    printl(list,n);
}
void print(vector<int> vec){
    printv(vec);
}
#endif // !__PRINT_H_
