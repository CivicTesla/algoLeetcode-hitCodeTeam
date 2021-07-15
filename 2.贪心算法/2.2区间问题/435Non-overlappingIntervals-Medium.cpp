#include <iostream>//cout
#include <algorithm>//sort()
#include <vector>//vector<int>数组
#include <numeric>//accumulate()求和
using namespace std;

//! 题目：给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
//t O()|O()
class solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
            return a[1] < b[1];//* lambda表达式，根据每个区间的右端进行排序，从小到大
        });
        int total = 0, prev = intervals[0][1];//total用于收集for循环中需要移除的区间
        for (int i = 1; i < n; ++i) {
            if (intervals[i][0] < prev) {//当前区间若与前一个区间相交，则total+1，再判断下一个区间
                ++total;
            } else {
                prev = intervals[i][1];//当前区间与前一个区间不相交，则将prev替换为当前区间，再与下一个区间进行相交判断
            } 
        }
        return total;
    }
};

int main(){
    // ----------输入：[[1,2],[2,4],[1,3]]
    int element0[2] = {1,2};
    vector<int> interval0(element0, element0+2);
    int element1[2] = {1,2};
    vector<int> interval1(element1, element1+2);
    int element2[2] = {1,2};
    vector<int> interval2(element2, element2+2);
    
    vector<int> ele[3] = {interval0,interval1,interval2};
    vector<vector<int>> interval(ele,ele+3);
    // ----------输入结束

    solution solve;
    cout << solve.eraseOverlapIntervals(interval) << endl;
}