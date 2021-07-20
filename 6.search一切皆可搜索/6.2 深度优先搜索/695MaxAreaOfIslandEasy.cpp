#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
#include <stack>
using namespace std;

class Solution
{
public:
    //t O()|O()
    vector<int> direction{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0, local_area, area = 0, x, y;
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])
                {
                    local_area = 1;
                    grid[i][j] = 0;
                    stack<pair<int, int>> island;
                    island.push({i, j});
                    while (!island.empty())
                    {
                        auto [r, c] = island.top(); //b C++17语法，若编译器报版本错，g编译器命令后这样添加：g++ -std=c++17
                        island.pop();
                        for (int k = 0; k < 4; ++k)
                        {
                            x = r + direction[k], y = c + direction[k + 1];
                            if (x >= 0 && x < m &&
                                y >= 0 && y < n && grid[x][y] == 1)
                            {
                                grid[x][y] = 0;
                                ++local_area;
                                island.push({x, y});
                            }
                        }
                    }
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }
};

// 测试
TimeTEST(test_1) //测试用例，可以有多个，自定义说明test_1
{
    std::cout << "this is test_1" << std::endl;
    //构造数组
    vector<vector<int>> vec{{1,0,1,1,0,1,0,1},{1,0,1,1,0,1,1,1},{0,0,0,0,0,0,0,1}};
    // 类实例化
    Solution solve;
    cout << solve.maxAreaOfIsland(vec) << endl;

}