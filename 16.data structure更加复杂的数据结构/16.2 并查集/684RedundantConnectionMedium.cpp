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
    //t O(NlogN)|O(N)
    //t 时间复杂度：O(NlogN)，其中 N 是图中的节点个数。
    //t 需要遍历图中的 N 条边，对于每条边，需要对两个节点查找祖先，如果两个节点的祖先不同则需要进行合并，需要进行 2 次查找和最多 1 次合并。
    //t 一共需要进行 2N 次查找和最多 N 次合并，因此总时间复杂度是O(2NlogN)=O(NlogN)。
    //t 这里的并查集使用了路径压缩，但是没有使用按秩合并，最坏情况下的时间复杂度是 O(NlogN)，
    //t 平均情况下的时间复杂度依然是 O(Nα(N))，其中 α 为阿克曼函数的反函数，α(N) 可以认为是一个很小的常数。

    // t 空间复杂度：O(N)，其中 N 是图中的节点个数。使用数组 parent 记录每个节点的祖先。

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