/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* flattenReturnLast(TreeNode* root) {
    TreeNode* last = root;
    TreeNode* right =
        root->right;  // ATTENTION: store right in temporary variable
    if (root->left) {
      last->right = root->left;
      last = flattenReturnLast(root->left);
      root->left = nullptr;
    }
    if (right) {
      last->right = right;
      last = flattenReturnLast(right);
    }
    return last;
  }
  void flatten(TreeNode* root) {
    if (root) flattenReturnLast(root);
  }
};
