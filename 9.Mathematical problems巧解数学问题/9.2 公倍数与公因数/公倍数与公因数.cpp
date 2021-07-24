#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
#include "../../include/breaknine/print.h"
using namespace std;

class Solution {
public:
    //t O()|O()
    // todo1 辗转相除法，求两个数的最大公因数；最小公倍数=两个数相乘/最大公因数
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    int lcm(int a, int b)
    {
        return a * b / gcd(a, b);
    }
    // todo2 扩展欧几里得算法
    // ？欧几里得
    int xGCD(int a, int b, int &x, int &y)
    {
        if (!b)
        {
            x = 1, y = 0;
            return a;
        }
        int x1, y1, gcd = xGCD(b, a % b, x1, y1);
        x = y1, y = x1 - (a / b) * y1;
        return gcd;
    }
};

// 测试
TimeTEST(test_1)
{
    std::cout << "this is test_1" << std::endl;

    // *类实例化
    Solution solve;
    
    
    // * ------显示整数结果
    print(solve.gcd(9,3));
    print(solve.lcm(9,3));
    print(solve.xGCD(9,3));//？？？
}