#include <stdio.h>
#include <vector>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
  TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int i_start,
                   int i_end, int p_start, int p_end) {
    if (i_start > i_end)
      return nullptr;
    TreeNode *node = new TreeNode(postorder[p_end]);
    int cut = i_start;
    while (inorder[cut] != postorder[p_end])
      cut++;
    node->left = helper(inorder, postorder, i_start, cut - 1, p_start,
                        p_start + cut - i_start - 1);
    node->right = helper(inorder, postorder, cut + 1, i_end,
                         p_start + cut - i_start, p_end - 1);
    return node;
  }

public:
  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
    if (inorder.empty())
      return nullptr;
    return helper(inorder, postorder, 0, inorder.size() - 1, 0,
                  postorder.size() - 1);
  }
};
