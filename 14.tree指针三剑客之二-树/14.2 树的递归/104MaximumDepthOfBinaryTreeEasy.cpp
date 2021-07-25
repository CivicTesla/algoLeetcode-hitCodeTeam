#include <iostream>
#include <algorithm>
#include <vector>
#include "../../include/breaknine/print.h"
using namespace std;

struct TreeNode//创建树
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    //t O()|O()
    //原理：比较左子树和右子树的最大深度max(l,r)，那么当前节点的最大深度即为max()+1
    int maxDepth(TreeNode *root){//递归求树的深度
    //todo1 一句话写法:
        // return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;//t 判断条件：root? ，非空则返回第一个值。空则返回第二个值0;遇到空节点时返回0,递归到数的最底层节点时，max()返回0
    //todo2 if写法:
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
// 测试
int main() {
    // 创建树
    TreeNode *tree = new TreeNode(3);
    tree->left = new TreeNode(9);tree->right=new TreeNode(20);
    tree->right->left=new TreeNode(15);tree->right->right=new TreeNode(7);
    
    // 类实例化
    Solution solve;
    // 显示结果
    print(solve.maxDepth(tree));
}