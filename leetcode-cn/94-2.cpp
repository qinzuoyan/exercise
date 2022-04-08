#include <stack>
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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> vec;
    stack<TreeNode *> s;
    TreeNode *p = root;
    while (p || !s.empty()) {
      while (p) {
        s.push(p);
        p = p->left;
      }
      if (!s.empty()) {
        TreeNode *t = s.top();
        s.pop();
        vec.push_back(t->val);
        p = t->right;
      }
    }
    return vec;
  }
};
