//! 题目：
//! 假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。
//! 给你一个整数数组  flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。另有一个数 n ，能否在不打破种植规则的情况下种入 n 朵花？能则返回 true ，不能则返回 false。

//! 示例 1：
//! 输入：flowerbed = [1,0,0,0,1], n = 1
//! 输出：true

//! 示例 2：
//! 输入：flowerbed = [1,0,0,0,1], n = 2
//! 输出：false

#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>


using namespace std;

class Solution {//leetcode官网答案
public:
    //* 从贪心的角度考虑，应该在不打破种植规则的情况下种入尽可能多的花，然后判断可以种入的花的最多数量是否大于或等于 n。
    //* 计算花坛中可以种入的花的最多数量，判断是否大于或等于 n 即可
    //* prev 表示上一朵已经种植的花的下标位置，初始时prev=−1，表示尚未遇到任何已经种植的花。
    //* 从左往右遍历数组flowerbed，当遇到flowerbed[i]=1 时根据prev 和 ii 的值计算上一个区间内可以种植花的最多数量，
    //* 然后令prev=i，继续遍历数组flowerbed 剩下的元素。
    //* 遍历数组flowerbed 结束后，根据数组 prev 和长度 m 的值计算最后一个区间内可以种植花的最多数量。
    //* 判断整个花坛内可以种入的花的最多数量是否大于或等于 n。
    //t O(m)|O(1)
    bool canPlaceFlowers0(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; ++i) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    count += (i - prev - 2) / 2;
                }
                prev = i;
            }
        }
        if (prev < 0) {
            count += (m + 1) / 2;
        } else {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
    
    //* 由于只需要判断能否在不打破种植规则的情况下在花坛内种入 n 朵花，不需要具体知道最多可以在花坛内种入多少朵花，
    //* 因此可以在循环内进行优化，当可以种入的花的数量已经达到 n，则可以直接返回true，不需要继续计算数组剩下的部分。
    //t O(m)|O(1)
    bool canPlaceFlowers1(vector<int>& flowerbed, int n) {
        int count = 0;
        int m = flowerbed.size();
        int prev = -1;
        for (int i = 0; i < m; i++) {
            if (flowerbed[i] == 1) {
                if (prev < 0) {
                    count += i / 2;
                } else {
                    count += (i - prev - 2) / 2;
                }
                if (count >= n) {
                    return true;
                }
                prev = i;
            }
        }
        if (prev < 0) {
            count += (m + 1) / 2;
        } else {
            count += (m - prev - 1) / 2;
        }
        return count >= n;
    }
};
int main(){
    Solution solve;
    int ele[] = { 1,0,0,0,1,0,1,0,0,0,0,1,0,0,0 };
    vector<int> vec(ele, ele+sizeof(ele)/sizeof(int));//sizeof(ele)用于统计int ele[]所有元素的字节数，sizeof(int)表示单个int类型所占字节数，两者相除即ele[]中元素的个数
    cout << solve.canPlaceFlowers1(vec,1) << endl;//* 返回1表示true，0表示false

// t------测试c艹的bool返回值
    bool t;
    t = 1>2;
    cout << t << endl;
// t------测试c艹的bool返回值 结束



}
