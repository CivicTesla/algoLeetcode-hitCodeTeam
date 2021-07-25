#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>//iota
#include "../../include/breaknine/print.h"
using namespace std;

//!RedundantConnection,冗余连接

class UF
{
    vector<int> id;

public:
    UF(int n) : id(n)
    {
        iota(id.begin(), id.end(), 0); // iota函数可以把数组初始化为0到n-1
    }
    int find(int p)
    {
        while (p != id[p])
        {
            p = id[p];
        }
        return p;
    }
    void connect(int p, int q)
    {
        id[find(p)] = find(q);
    }
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
};
class Solution
{
public:
    //t O()|O()
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        int n = edges.size();
        UF uf(n + 1);
        for (auto e : edges)
        {
            int u = e[0], v = e[1];
            if (uf.isConnected(u, v))
            {
                return e;
            }
            uf.connect(u, v);
        }
        return vector<int>{-1, -1};
    }
};

// 测试
int main()
{
    // 构造二维数组
    vector<vector<int>> vec{{1,2}, {1,3}, {2,3}};

    // 类实例化
    Solution solve;

    // 显示结果
    printv(solve.findRedundantConnection(vec));
}