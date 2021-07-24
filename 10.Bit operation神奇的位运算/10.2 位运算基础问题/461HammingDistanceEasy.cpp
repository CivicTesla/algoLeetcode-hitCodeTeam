#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
#include "../../include/breaknine/print.h"
using namespace std;

//! 汉明距离（Hamming distance，即两个二进制数之间不同位的个数）。
class Solution {
public:
    //t O()|O()
    int hammingDistance(int x, int y)
    {
        int diff = x ^ y, ans = 0;// ^，异或运算符，相同返回1
        while (diff)//非0则true
        {
            print("------第n次循环------");
            ans += diff & 1;// and 运算符,11为1，其他为0；目的：检测最后一位是否为1，是则ans++
            diff >>= 1;// 右移1位，最后一位已被检测，这里移走它，shile循环检测下一位，直到diff为0；
        }
        return ans;
    }
};

// 测试
TimeTEST(test_1)
{
    std::cout << "this is test_1" << std::endl;
    //* 类实例化
    Solution solve;
    // * ------显示整数结果
    print(solve.hammingDistance(1,4));//1bin:0001,4bin:0100
}