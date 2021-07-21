#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/test/timeTest.h"
#include <stack>
using namespace std;

class Solution
{
public:
    //t O(m x n)|O(m x n)
    vector<int> direction{-1, 0, 1, 0, -1};
    //todo1 ------------原理：使用栈实现深度优先搜索------------
    int maxAreaOfIsland0(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = m ? grid[0].size() : 0, local_area, area = 0, x, y;//矩阵m x n
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (grid[i][j])//值为1，是true
                {
                    local_area = 1;
                    grid[i][j] = 0;//遍历过的元素，值改为0
                    stack<pair<int, int>> island;
                    island.push({i, j});//把二维数组中值为1的元素的坐标推入栈中
                    while (!island.empty())//栈非空
                    {
                        auto [r, c] = island.top(); //b auto,C++17语法，若编译器报版本错，g编译器命令后这样添加：g++ -std=c++17
                        island.pop();//auto无法识别pop()返回的类型
                        for (int k = 0; k < 4; ++k)//遍历当前元素的上右下左
                        {
                            x = r + direction[k], y = c + direction[k + 1];
                            if (x >= 0 && x < m &&
                                y >= 0 && y < n && grid[x][y] == 1)
                            {
                                grid[x][y] = 0;//遍历过的元素，值改为0
                                ++local_area;
                                island.push({x, y});//若元素值为1，加入栈中
                            }
                        }
                    }
                    area = max(area, local_area);
                }
            }
        }
        return area;
    }
    //todo2.1 ------------递归实现，写法1------------
    int maxAreaOfIsland1(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    max_area = max(max_area, dfs1(grid, i, j));
                }
            }
        }
        return max_area;
    }

    int dfs1(vector<vector<int>> &grid, int r, int c)
    {
        if (grid[r][c] == 0)
            return 0;
        grid[r][c] = 0;
        int x, y, area = 1;
        for (int i = 0; i < 4; ++i)
        {
            x = r + direction[i], y = c + direction[i + 1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
            {
                area += dfs1(grid, x, y);
            }
        }
        return area;
    }
    //todo2 ------------递归实现，写法2------------
    int maxAreaOfIsland2(vector<vector<int>> &grid)
    { 
        if (grid.empty() || grid[0].empty())
            return 0;
        int max_area = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                max_area = max(max_area, dfs2(grid, i, j));
            }
        }
        return max_area;
    }

    int dfs2(vector<vector<int>> &grid, int r, int c)
    {
        if (r < 0 || r >= grid.size() ||
            c < 0 || c >= grid[0].size() || grid[r][c] == 0)
        {
            return 0;
        }
        grid[r][c] = 0;
        return 1 + dfs2(grid, r + 1, c) + dfs2(grid, r - 1, c) + dfs2(grid, r, c + 1) + dfs2(grid, r, c - 1);
    }
};

// 测试
TimeTEST(test1_stack)
{
    std::cout << "this is stack" << std::endl;
    //构造数组
    vector<vector<int>> vec{{1,0,1,1,0,1,0,1},{1,0,1,1,0,1,1,1},{0,0,0,0,0,0,0,1}};
    // 类实例化
    Solution solve;
    cout << solve.maxAreaOfIsland0(vec) << endl;
}
TimeTEST(test1_recursion1)
{
    std::cout << "this is recursion1" << std::endl;
    //构造数组
    vector<vector<int>> vec{{1,0,1,1,0,1,0,1},{1,0,1,1,0,1,1,1},{0,0,0,0,0,0,0,1}};
    // 类实例化
    Solution solve;
    cout << solve.maxAreaOfIsland2(vec) << endl;

}
TimeTEST(test1_recursion2)
{
    std::cout << "this is recursion2" << std::endl;
    //构造数组
    vector<vector<int>> vec{{1,0,1,1,0,1,0,1},{1,0,1,1,0,1,1,1},{0,0,0,0,0,0,0,1}};
    // 类实例化
    Solution solve;
    cout << solve.maxAreaOfIsland2(vec) << endl;
}
