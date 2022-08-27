#include <deque>
#include <string>
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
  int width(const string &a, const string &b) {
    int r = 0, k = 1, s = a.size(), l = 0;
    for (int i = s - 1; i >= 0 && k > 0; --i) {
      if (l == 0) {
        if (b[i] > a[i])
          r += k;
        else if (b[i] < a[i]) {
          r += k;
          l = 1;
        }
      } else {
        if (b[i] > a[i])
          l = 0;
        else if (b[i] == a[i])
          r += k;
      }
      k <<= 1;
    }
    return r;
  }

  int widthOfBinaryTree(TreeNode *root) {
    if (root == nullptr)
      return 0;
    int m = 0;
    deque<pair<TreeNode *, string>> p, q;
    p.emplace_back(root, "0");
    while (p.size()) {
      int k = p.size() == 1 ? 1 : width(p.front().second, p.back().second) + 1;
      if (k > m)
        m = k;
      q.clear();
      for (auto &kv : p) {
        if (kv.first->left)
          q.emplace_back(kv.first->left, kv.second + "0");
        if (kv.first->right)
          q.emplace_back(kv.first->right, kv.second + "1");
      }
      p.swap(q);
    }
    return m;
  }
};
