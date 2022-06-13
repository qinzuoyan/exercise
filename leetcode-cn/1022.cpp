/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int sumRootToLeaf(TreeNode *root, int k) {
    k = (k << 1) | root->val;
    if (root->left || root->right)
      return (root->left ? sumRootToLeaf(root->left, k) : 0) +
             (root->right ? sumRootToLeaf(root->right, k) : 0);
    else
      return k;
  }

  int sumRootToLeaf(TreeNode *root) {
    if (!root) return 0;
    return sumRootToLeaf(root, 0);
  }
};
