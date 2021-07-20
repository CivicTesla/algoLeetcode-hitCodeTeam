#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
using namespace std;

// ! 给定一个非负整数，求它的开方，向下取整。
class Solution {
public://* public关键字暴露类Solution内部的对象，才能被其他类如main()访问到
    //t O(logn)|O()
    int mySqrt(int num) {
        if (num == 0) return num;
        int l = 1, r = num, mid, sqrt;
        while (l <= r) {
            mid = l + (r - l) / 2;// 取整 区间[l,r]中间的数
            sqrt = num / mid;//* sqrt*mid=num，两者相等的时候，mid的值就是解
            if (sqrt == mid) {
                return mid;
            } else if (mid > sqrt) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return r;
    }
};

// 测试
TimeTEST(test_1)//测试用例，可以有多个，自定义说明test_1
{
    cout << "this is test_1" << endl;
    //构造数组
    Solution solve;
    cout << solve.mySqrt(8) << endl;
    // c++除法取整
    int i = 1/2;
    cout << i << endl;//* 结果为1
}