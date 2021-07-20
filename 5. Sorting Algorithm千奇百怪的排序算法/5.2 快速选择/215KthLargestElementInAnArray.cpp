#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
using namespace std;

class Solution {
public://* public关键字暴露类Solution内部的对象，才能被其他类如main()，TimeTEST()访问到
    //t 如果只是用快速排序，即把数组所有元素排好，再返回对应的目标值，则O(nlogn)|O(1)
    //t 这里使用快速选择排序，随机选取一个基准点，时间与每次划分出来的子区间长度相关，最坏O(n^2)，每次都是长度为[1,n-1]\平均O(n)|O(1)
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1, target = nums.size() - k; //若有6个数，索引号0，1，2，3，4，5，第k大的数的索引号是6-k 
        while (l < r) {
            int mid = quickSelection(nums, l, r);//t0.1 该函数每运行一次，会返回一个索引号，在nums中对应的值
            // 判断quickSelection()返回来的索引号是否等于目标值,等于则返回该索引对应的nums数组的值，算法结束。否，若小于目标值，则说明目标值在mid右边，若大于目标值，则说明目标值在左边
            if (mid == target) {
                return nums[mid];
            }
            if (mid < target) {//找到的数nums[mid]比目标值小，就把判断区间nums区间设置为(mid+1，r),再进行快速选择quickSelection()，不断调用快速选择函数(递归)
                l = mid + 1;
            } else {
                r = mid - 1;
            } 
        }
        return nums[l];
    }
    // ???快速选择原理
    // 快速选择;https://www.bilibili.com/video/BV1Tt411r75A/?spm_id_from=333.788.recommend_more_video.1
    int quickSelection(vector<int>& nums, int l, int r) {//t0.2 对nums进行增序排列，每一次运行将会把基准数交换到它该在的索引号上，即j
        int i = l + 1, j = r;
        // ! 快速选择排序说明：基准点的设置可以随机(通常打乱数组)，可设为中间或左右两端，这里设为判断区间左端第一个数，对其进行快速选择排序，将返回按增序来排列nums的索引号。
        while (true) {//* 将nums最左端的数设为基准点，即n[l]为基准数，其中l=0；i为左指针，从l+1即1开始，j为右指针；两指针朝向对方运动
            while (i < r && nums[i] <= nums[l]) {//寻找比基准数大的数;//* 先移动左指针，再移动右指针
                ++i;
            }
            while (l < j && nums[j] >= nums[l]) {//寻找比基准数小的数
                --j;
            }
            if (i >= j) {
                break;//todo2.1 i j超过对方，跳出if的最近一层的while 
            }
            swap(nums[i], nums[j]);//todo1 当i，j指针并没有移动超过对方，先交换nums[i]和nums[j],再交换nums[l]和nums[j]
        }
        swap(nums[l], nums[j]);//todo2.2 ，基准数和nums[j]交换
        return j;//增序排列，快速选择函数运行后将改变nums的排列，返回索引号j，j左边的数都比mid小，j右边的数都比mid大
    }
};

// 测试
TimeTEST(test_1)//测试用例，可以有多个，自定义说明test_1
{
    std::cout << "this is test_1" << std::endl;
    Solution solve;
    vector<int> vec{3,2,5,1,6,4};
    int k = 3;
    int Kth = solve.findKthLargest(vec,k);
    cout << Kth << endl;
    
}