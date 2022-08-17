#include <deque>
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
  int deepestLeavesSum(TreeNode *root) {
    if (root == nullptr)
      return 0;
    deque<TreeNode *> p, q;
    p.push_back(root);
    while (p.size()) {
      int s = 0;
      q.clear();
      for (auto n : p) {
        if (n->left)
          q.push_back(n->left);
        if (n->right)
          q.push_back(n->right);
        s += n->val;
      }
      if (q.empty())
        return s;
      p.swap(q);
    }
    return 0;
  }
};
