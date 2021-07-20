#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
using namespace std;

//! 找到数组中相加之和等于target的两个数，找到立即返回，只找一组

class Solution {
public://* public关键字暴露类Solution内部的对象，才能被其他类如main()访问到
//t 最大为O(n)|O(1)
    vector<int> twoSum(vector<int>& numbers, int target) {//*两个指针从数组（已排序排序）两端开始，朝着对方运动，因此时间最大为O（n）
    int l = 0, r = numbers.size() - 1, sum;
    while (l < r) {
        sum = numbers[l] + numbers[r];
        if (sum == target) break;//* 一旦找到，立即打破循环体while
        if (sum < target) ++l;
        else --r;
    }
    return vector<int>{numbers[l], numbers[r]};//* 返回numbers中加起来等于target的两个数
    }
};

// 测试
TimeTEST(test_1)
{
    std::cout << "this is test_1" << std::endl;

    Solution solve;
    int ele[] = {2,7,11,15};
    vector<int> vec0(ele, ele+sizeof(ele)/sizeof(int));//* sizeof(ele)用于统计int ele[]所有元素的字节数，sizeof(int)表示单个int类型所占字节数，两者相除即ele[]中元素的个数
    int target = 9;

// * ----------------------显示数组
    vector<int> vec =  solve.twoSum(vec0,target);
    vector<int>::iterator ite = vec.begin();
	for (; ite != vec.end(); ite++){
		cout << *ite;
		cout << ",";
	}
    cout << endl;// * ----------------------显示数组结束
}