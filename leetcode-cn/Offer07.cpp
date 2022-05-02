#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  TreeNode *buildTree(int *preorder, int *inorder, int n) {
    if (n == 0)
      return nullptr;
    int v = *preorder, *p = inorder;
    while (*p != v)
      p++;
    TreeNode *r = new TreeNode(v);
    int l = p - inorder;
    r->left = buildTree(preorder + 1, inorder, l);
    r->right = buildTree(preorder + 1 + l, p + 1, n - l - 1);
    return r;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    int n = preorder.size();
    return n == 0 ? nullptr : buildTree(&preorder[0], &inorder[0], n);
  }
};
