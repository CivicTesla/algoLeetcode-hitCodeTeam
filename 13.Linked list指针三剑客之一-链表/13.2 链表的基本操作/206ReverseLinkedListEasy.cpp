#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/breaknine/print.h"
#include "../../include/breaknine/listNode.h"//自定义链表创建，输出
using namespace std;
//! 翻转链表
class Solution {
public:
    //t O()|O()

    ListNode *reverseList0(ListNode *head, ListNode *prev = nullptr)
    {
        if (!head)
        {
            return prev;
        }
        ListNode *next = head->next;
        head->next = prev;
        return reverseList0(next, head);
    }
    ListNode *reverseList1(ListNode *head)
    {
        ListNode *prev = nullptr, *next;
        while (head)
        {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    // ! leetcode中文官网答案
    ListNode *reverseList2(ListNode *head)//迭代
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    // t O(n)|O(n)
    ListNode* reverseList3(ListNode* head) {//递归
        if (!head || !head->next) {//head为空，下一个节点为空，都返回head;当遇到最后一个节点，返回最后一个节点
            return head;
        }
        ListNode* newHead = reverseList3(head->next);
        head->next->next = head;//  k+1的下一个节点指向k,所以k.next.next指向k。
        head->next = nullptr;//同时将当前节点设为空，这样当递归到第一个节点时，才会断掉（next设为nullptr）
        print("---process---");
        printLN(newHead);
        print("------");
        return newHead;
    }
};

// 测试
int main() {
    // 创建链表
    vector<double> vec{1,2,3};// 1->2->3->4
    ListNode *ln = listNode(vec);

    // 类实例化
    Solution solve;
    printLN(ln);
    print(ln->next->next->value);

    printLN(solve.reverseList3(ln));
    
    printLN(ln);
}