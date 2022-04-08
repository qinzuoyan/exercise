#include <algorithm>
using namespace std;

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
  static int sMax;

  // like problem 124
  int diameterOfBinaryTree(TreeNode *root) {
    sMax = 0;
    maxDepth(root);
    return sMax;
  }

  // @ret max depth of tree, and update `sMax'
  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    sMax = max(sMax, l + r);
    return max(l, r) + 1;
  }
};

int Solution::sMax = 0;
