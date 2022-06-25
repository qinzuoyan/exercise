#include <vector>
#include <climits>
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
  vector<int> largestValues(TreeNode *root) {
    vector<int> r;
    if (!root) return r;
    vector<TreeNode *> q, t;
    q.push_back(root);
    while (q.size()) {
      int m = INT_MIN;
      t.clear();
      for (auto n : q) {
        if (n->val > m) m = n->val;
        if (n->left) t.push_back(n->left);
        if (n->right) t.push_back(n->right);
      }
      r.push_back(m);
      q.swap(t);
    }
    return r;
  }
};
