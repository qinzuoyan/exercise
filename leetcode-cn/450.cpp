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
  TreeNode *deleteNode(TreeNode *root, int key) {
    TreeNode *p = root, *parent = nullptr;
    while (p && p->val != key) {
      parent = p;
      p = p->val > key ? p->left : p->right;
    }
    if (!p)
      return root;
    if (!p->left || !p->right) {
      TreeNode *t = p->left ? p->left : p->right;
      if (parent) {
        if (parent->left == p)
          parent->left = t;
        else
          parent->right = t;
      }
      delete p;
      return parent ? root : t;
    }
    TreeNode *q = p->right;
    parent = nullptr;
    while (q->left) {
      parent = q;
      q = q->left;
    }
    p->val = q->val;
    if (parent)
      parent->left = q->right;
    else
      p->right = q->right;
    delete q;
    return root;
  }
};
