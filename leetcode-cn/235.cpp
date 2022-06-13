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
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    if (p == q) {
      return p;
    }
    vector<pair<TreeNode *, int>> s, s1;
    if (root == p || root == q) {
      s1.emplace_back(root, 0);
    }
    s.emplace_back(root, 0);
    while (!s.empty()) {
      auto &pr = s.back();
      TreeNode *n = nullptr;
      if (pr.second == 0 && (n = pr.first->left)) {
        pr.second = 1;
        s.emplace_back(n, 0);
      } else if (pr.second <= 1 && (n = pr.first->right)) {
        pr.second = 2;
        s.emplace_back(n, 0);
      } else {
        s.pop_back();
      }
      if (n == p || n == q) {
        if (s1.empty()) {
          s1 = s;
        } else {
          int i = 0, j = 0, in = s.size(), jn = s1.size();
          while (i < in && j < jn && s[i].first == s1[j].first) {
            i++;
            j++;
          }
          return s[i - 1].first;
        }
      }
    }
    return nullptr;
  }
};
