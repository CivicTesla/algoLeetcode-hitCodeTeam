#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
#include "../../include/breaknine/print.h"
using namespace std;
// !给定 n 节台阶，每次可以走一步或走两步，求一共有多少种方式可以走完这些台阶。解法提示：斐波那契数列0，1，1，2，3。。。
class Solution {
public:
    //t O(n)|O(n)
    int climbStairs0(int n)
    {
        if (n <= 2)
            return n;
        vector<int> dp(n + 1, 1);//n+1个1
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
    //t O(n)|O(1)
    int climbStairs1(int n)
    {
        if (n <= 2)
            return n;
        int pre2 = 1, pre1 = 2, cur;
        for (int i = 2; i < n; ++i)
        {
            cur = pre1 + pre2;
            pre2 = pre1;
            pre1 = cur;
        }
        return cur;
    }
};

// 测试
TimeTEST(test_1)
{
    std::cout << "this is test_1" << std::endl;
    int input = 148;//? 48到100多附近的数，输出结果为负数
    Solution solve;
    print(solve.climbStairs0(input));

}