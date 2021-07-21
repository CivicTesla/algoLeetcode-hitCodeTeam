#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
#include "../../include/breaknine/print.h"
using namespace std;

class Solution {
public:
    //t O()|O()
    vector<int> func0(vector<int> vec,int target){
    }
    int func1(vector<int> vec,int target){
    }
};

// 测试
int main() {

    //*构造一维数组
    vector<int> vec{2,7,11,15};
    int target = 1 ;
    //* 构造二维数组
    vector<vector<int>> vec{{1,0,1,1,0,1,0,1},{1,0,1,1,0,1,1,1},{0,0,0,0,0,0,0,1}};

    //* 类实例化
    Solution solve;
    
    // * ------显示整数结果
    print(solve.func0(vec,target));
}