// This program illustrates the creation || of linked lists.
#ifndef __listNode_H_
#define __listNode_H_
#include "../../include/breaknine/print.h"

using namespace std;
//todo0 定义链表
struct ListNode
{
    double value;
    ListNode *next;
    //构造函数
    ListNode(double valuel, ListNode *nextl = nullptr)
    {
        value = valuel;
        next = nextl;
    }
};


//todo1 创建链表
ListNode *listNode(vector<double> vec)
{
    ListNode *numberlist = nullptr;

    vector<double>::iterator ite = vec.begin();
    for (vector<double>::iterator ite = vec.end()-1; ite >= vec.begin(); ite--) //vec.end()代表元素的个数;逆序循环
    {
        //创建一个结点以保存该数字
        numberlist = new ListNode(*ite, numberlist); 
    }
    // t ------逆序循环vector数组使用示范------
    //todo1.0 方法0：
    //set或者vector的变量名是myvec
    //第一个元素是从end-1开始的，end指向的不是最后一个元素
    // for (vector<double>::iterator ite = vec.end() - 1; ite >= vec.begin(); ite--)
    // {
    //     //处理逻辑自己定义，我这里自己直接输出了
    //     cout << *ite << endl;
    //     if (ite == vec.begin())
    //         break; //走到这里就不能再减了
    // }
    // todo1.1 方法1：
    // for (set<int>::reverse_iterator ite = vec.rbegin(); ite != vec.rend(); ++ite)//需要先引入 #include <set>
    // {
    //     cout << *ite << endl;
    // } //迭代器一定要使用reverse_iterator
    // t ------逆序循环vector数组使用示范结束------

    return numberlist;//! 不加*号，返回ListNode * 指针类型，同时函数要声明也要加*；加*号，*numberlist，返回ListNode类型
}
// todo3 输出链表
void printLN(ListNode *ln)//该函数放在主函数main中使用;//? ln改为*ln，对象ln的属性要使用->表示；ln类型则用.表示
{
    
    while (ln != nullptr)
    {
        cout << ln->value;
        ln = ln->next;
        if (ln != nullptr)
            cout << "->";
    }
    cout << endl;
}
#endif // !__listNode_H_

// t ------main函数中创建链表使用示范：

// int main(){
//     vector<double> vec{1,2,3};
//     ListNode *ln = listNode(vec);//以指针类型创建
//     printLN(ln);//b 输出链表
//     print(ln.next->next->value);//b 输出链表某个点的值
// }
// t ------main函数中创建链表使用示范结束