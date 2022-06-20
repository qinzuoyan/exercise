#include <set>
#include <unordered_map>
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
  int findFrequentTreeSum(TreeNode *root, unordered_map<int, int> &m) {
    if (!root) return 0;
    int l = findFrequentTreeSum(root->left, m);
    int r = findFrequentTreeSum(root->right, m);
    int s = l + r + root->val;
    ++m[s];
    return s;
  }

  vector<int> findFrequentTreeSum(TreeNode *root) {
    unordered_map<int, int> m;
    findFrequentTreeSum(root, m);
    set<int> s;
    int c = 0;
    for (auto &kv : m) {
      if (kv.second >= c) {
        if (kv.second > c) {
          c = kv.second;
          s.clear();
        }
        s.insert(kv.first);
      }
    }
    return vector<int>(s.begin(), s.end());
  }
};
