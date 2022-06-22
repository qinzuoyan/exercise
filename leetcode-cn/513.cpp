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
  int findBottomLeftValue(TreeNode *root) {
    deque<TreeNode *> q, t;
    TreeNode *r = nullptr;
    q.push_back(root);
    while (q.size()) {
      r = q.front();
      while (q.size()) {
        TreeNode *n = q.front();
        if (n->left) t.push_back(n->left);
        if (n->right) t.push_back(n->right);
        q.pop_front();
      }
      q = std::move(t);
    }
    return r->val;
  }
};
