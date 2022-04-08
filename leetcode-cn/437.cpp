#include <map>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int pathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return 0;
    map<int, int> mp;
    return pathSum(root, targetSum, mp);
  }

  int pathSum(TreeNode* root, int targetSum, map<int, int>& mp) {
    int c = 0;
    mp[root->val]++;
    if (root->val == targetSum) {
      c++;
    }
    if (root->left) {
      map<int, int> m;
      c += pathSum(root->left, targetSum, m);
      c += m[targetSum - root->val];
      for (auto& p : m) {
        mp[root->val + p.first] += p.second;
      }
    }
    if (root->right) {
      map<int, int> m;
      c += pathSum(root->right, targetSum, m);
      c += m[targetSum - root->val];
      for (auto& p : m) {
        mp[root->val + p.first] += p.second;
      }
    }
    return c;
  }
};
