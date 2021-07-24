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
    int maxDepth(TreeNode *root)
    {
        return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
    }
};

// 测试
int main() {
    // 创建树
    TreeNode *root;root->val=3;
    TreeNode *left;left->val=9;
    TreeNode *right;right->val=20;root->left=left;root->right=right;
    

    // 类实例化
    Solution solve;
    print(root->val);
    // 显示结果
    // print(solve.maxDepth(root));
}