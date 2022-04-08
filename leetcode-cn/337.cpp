#include <algorithm>
#include <utility>
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
  // return <stealMax, noStealMax>
  pair<int, int> robMax(TreeNode *root) {
    if (root == nullptr) return make_pair(0, 0);
    pair<int, int> l = robMax(root->left);
    pair<int, int> r = robMax(root->right);
    return make_pair(root->val + l.second + r.second,
                     max(l.first, l.second) + max(r.first, r.second));
  }

  int rob(TreeNode *root) {
    pair<int, int> p = robMax(root);
    return max(p.first, p.second);
  }
};
