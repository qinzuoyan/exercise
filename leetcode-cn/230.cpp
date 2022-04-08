#include <stack>
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
  int kthSmallest(TreeNode *root, int k) {
    int i = 0;
    TreeNode *p = root;
    stack<TreeNode *> s;
    s.push(root);
    while (p || !s.empty()) {
      while (p) {
        s.push(p);
        p = p->left;
      }
      if (++i == k) {
        return s.top()->val;
      }
      p = s.top()->right;
      s.pop();
    }
    return 0;
  }
};
