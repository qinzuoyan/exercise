/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    if (root == nullptr || p == nullptr) return nullptr;
    if (p->right) {
      p = p->right;
      while (p && p->left) p = p->left;
      return p;
    } else {
      TreeNode *q = root, *r = nullptr;
      while (q->val != p->val) {
        if (q->val > p->val) {
          r = q;
          q = q->left;
        } else {
          q = q->right;
        }
      }
      return r;
    }
  }
};
