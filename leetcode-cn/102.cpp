#include <vector>
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> r;
    if (!root) return r;
    vector<TreeNode *> v, w;
    v.push_back(root);
    while (!v.empty()) {
      w.clear();
      r.push_back(vector<int>());
      vector<int> &b = r.back();
      for (size_t i = 0; i < v.size(); i++) {
        TreeNode *n = v[i];
        b.push_back(n->val);
        if (n->left) w.push_back(n->left);
        if (n->right) w.push_back(n->right);
      }
      w.swap(v);
    }
    return r;
  }
};
