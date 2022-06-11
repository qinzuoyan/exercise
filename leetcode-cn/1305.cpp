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
  vector<int> travel(TreeNode *root) {
    vector<int> v;
    stack<TreeNode *> s;
    TreeNode *n = root;
    while (n || s.size()) {
      while (n) {
        s.push(n);
        n = n->left;
      }
      if (s.size()) {
        v.push_back(s.top()->val);
        n = s.top()->right;
        s.pop();
      }
    }
    return v;
  }
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> v1 = travel(root1);
    vector<int> v2 = travel(root2);
    vector<int> v;
    auto it1 = v1.begin(), it2 = v2.begin();
    while (it1 != v1.end() && it2 != v2.end()) {
      if (*it1 <= *it2) {
        v.push_back(*it1);
        ++it1;
      } else {
        v.push_back(*it2);
        ++it2;
      }
    }
    if (it1 != v1.end()) v.insert(v.end(), it1, v1.end());
    if (it2 != v2.end()) v.insert(v.end(), it2, v2.end());
    return v;
  }
};
