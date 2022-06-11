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

class TreeTraveler {
  stack<TreeNode *> s;

 public:
  TreeTraveler(TreeNode *root) {
    while (root) {
      s.push(root);
      root = root->left;
    }
  }
  ~TreeTraveler() {}
  bool hasNext() { return !s.empty(); }
  int getNext() { return s.top()->val; }
  void popNext() {
    TreeNode *n = s.top()->right;
    s.pop();
    while (n) {
      s.push(n);
      n = n->left;
    }
  }
};

class Solution {
 public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> v;
    TreeTraveler tr1(root1), tr2(root2);
    while (tr1.hasNext() && tr2.hasNext()) {
      int i1 = tr1.getNext(), i2 = tr2.getNext();
      if (i1 <= i2) {
        v.push_back(i1);
        tr1.popNext();
      } else {
        v.push_back(i2);
        tr2.popNext();
      }
    }
    while (tr1.hasNext()) {
      v.push_back(tr1.getNext());
      tr1.popNext();
    }
    while (tr2.hasNext()) {
      v.push_back(tr2.getNext());
      tr2.popNext();
    }
    return v;
  }
};
