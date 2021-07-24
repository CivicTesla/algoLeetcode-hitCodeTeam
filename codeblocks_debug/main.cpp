#include <iostream>
#include <algorithm>
#include <vector>
#include "../include/breaknine/print.h"
using namespace std;
// ! 长度为 n 的数组，最大整数为n，查找不在 范围为 1 到 n 的整数
class Solution {
public:
    //t O()|O()
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> ans;
        for (const int &num : nums)//迭代容器中所有的元素，每一个元素的临时名字就是num
        {
            int pos = abs(num) - 1;//1.步骤0将nums的元素改为负值，因此这里abs改为正值
            print("------");
            print(pos);
            if (nums[pos] > 0)
            {
                nums[pos] = -nums[pos];//0.将出现过的数对应的索引的nums的元素改为负值
                print(nums[pos]);
            }
        }
        print("------");
        print(nums);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)//* 检测哪些下标的数大于0
            {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }
};

// 测试
int main()
{
    std::cout << "this is test_1" << std::endl;
    //* 构造一维数组
    vector<int> vec{4,3,2,7,8,2,3,1};

    //* 类实例化
    Solution solve;
    print(solve.findDisappearedNumbers(vec));
}
