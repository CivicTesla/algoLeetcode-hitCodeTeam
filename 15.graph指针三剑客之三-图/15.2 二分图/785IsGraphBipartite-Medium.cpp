#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include "../../include/breaknine/print.h"
using namespace std;
// ！用两种颜色对图中的节点进行着色，并且保证相邻的节点颜色不同，那么图为二分
class Solution
{
public:
    
    // 算法思路：给节点染色，用 0 表示未检查的节点，用 1 和 2 表示两种不同的颜色，若能成功染完，说明是二向图
    //todo0 原理：广度优先搜索
    //t O(N+M)，其中 N 和 M 分别是无向图中的点数和边数。O(N)，存储节点颜色的数组需要 O(N) 的空间，并且在广度优先搜索的过程中，队列中最多有 N-1 个节点，需要 O(N) 的空间。
    bool isBipartite(vector<vector<int>> &graph)
    {
        int n = graph.size();
        if (n == 0)
        {
            return true;
        }
        vector<int> color(n, 0);
        queue<int> q;//与栈一样，是一种线性存储结构,先进先出,在队尾添加元素，在队头删除元素
        for (int i = 0; i < n; ++i)//* 遍历所有图的节点
        {
            if (!color[i])//非0则true，未染色，将当前节点i送入队，并染颜色1
            {
                q.push(i);
                color[i] = 1;
            }
            while (!q.empty())//只要队列不是空的，就进行while循环
            {
                int node = q.front();
                q.pop();
                for (const int &j : graph[node])//循环取出graph[node]的元素，赋予给j；graph[node]，当前节点的邻接点
                {
                    if (color[j] == 0)//判断邻节点是否染染色
                    {
                        q.push(j);
                        color[j] = color[node] == 2 ? 1 : 2;//给邻接点染上与当前节点不同的颜色
                    }
                    else if (color[node] == color[j])//如果遇到邻接点有颜色，且颜色与当前节点相同，返回false，算法结束，该图不可二分
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// 测试
int main()
{
    // Input: [[1,3], [0,2], [1,3], [0,2]]
    // 0—— ——1
    // |     |
    // |     |
    // 3—— ——2
    // Output: true
    // 构造二维数组表示邻接链表，邻接链表表示图
    vector<vector<int>> vec{{1, 3}, {0, 2}, {1, 3}, {0, 2}};

    // 类实例化
    Solution solve;

    // 显示结果，表示图是否二分
    if (solve.isBipartite(vec))
        print("true");
}