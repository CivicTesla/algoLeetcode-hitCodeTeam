#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>//iota
#include "./include/breaknine/print.h"
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
// todo1 leetcode中文官网答案
// 原理：并查集
// t O()|O()
class Solution1 {
public:
    int Find(vector<int>& parent, int index) {//查找节点是否有连接；如果1已经连接2，1和3有连接，此时将2和3连接，1->2->3
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {//建立两个节点的连接
        parent[Find(parent, index1)] = Find(parent, index2);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int nodesCount = edges.size();//边的个数，3边
        vector<int> parent(nodesCount + 1);//父节点4个,默认为0
        for (int i = 1; i <= nodesCount; ++i) {
            parent[i] = i;//0,1,2,3
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2)) {//* 若两个节点没有连接，则将他们联系在一起
                Union(parent, node1, node2);
            } else {//* 若两个节点在parent中有连接，则说明此次循环的edge是多余的，算法结束，返回该边
                return edge;
            }
        }
        return vector<int>{};
    }
};

// 测试
int main()
{
    // 构造二维数组
    vector<vector<int>> vec{{1,2}, {1,3}, {2,3}};

    // 类实例化
    Solution1 solve;

    // 显示结果
    printv(solve.findRedundantConnection(vec));
}