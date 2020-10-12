#include <algorithm>
#include <stdio.h>

struct TreeNode {
    int       val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL) {}
};

// 超时
class Solution {
  public:
    int rob(TreeNode *root) {
        if (root == nullptr) return 0;
        int money = root->val;
        if (root->left)
            money += (rob(root->left->left) + rob(root->left->right));
        if (root->right)
            money += (rob(root->right->left) + rob(root->right->right));
        return std::max(money, rob(root->left) + rob(root->right));
    }
};
