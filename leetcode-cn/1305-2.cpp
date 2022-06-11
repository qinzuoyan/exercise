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

class TreeForwardIterator {
  stack<TreeNode *> s;
  TreeForwardIterator(TreeNode *n) {
    while (n) {
      s.push(n);
      n = n->left;
    }
  }
  friend class TreeTraveler;

 public:
  TreeForwardIterator() {}
  ~TreeForwardIterator() {}
  int &operator*() { return s.top()->val; }
  int *operator->() { return &(s.top()->val); }
  TreeForwardIterator &operator++() {
    TreeNode *n = s.top()->right;
    s.pop();
    while (n) {
      s.push(n);
      n = n->left;
    }
    return *this;
  }
  TreeForwardIterator operator++(int) {
    TreeForwardIterator t(*this);
    ++(*this);
    return t;
  }
  friend bool operator==(const TreeForwardIterator &x,
                         const TreeForwardIterator &y) {
    return x.s.size() == y.s.size() && (x.s.empty() || x.s.top() == y.s.top());
  }
  friend bool operator!=(const TreeForwardIterator &x,
                         const TreeForwardIterator &y) {
    return !(x == y);
  }
};

class TreeTraveler {
  TreeNode *root_;

 public:
  TreeTraveler(TreeNode *root) : root_(root) {}
  ~TreeTraveler() {}
  TreeForwardIterator begin() { return TreeForwardIterator(root_); }
  TreeForwardIterator end() { return TreeForwardIterator(); }
};

class Solution {
 public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> v;
    TreeTraveler tr1(root1), tr2(root2);
    auto it1 = tr1.begin(), it2 = tr2.begin();
    while (it1 != tr1.end() && it2 != tr2.end()) {
      if (*it1 <= *it2) {
        v.push_back(*it1);
        ++it1;
      } else {
        v.push_back(*it2);
        ++it2;
      }
    }
    while (it1 != tr1.end()) {
      v.push_back(*it1);
      ++it1;
    }
    while (it2 != tr2.end()) {
      v.push_back(*it2);
      ++it2;
    }
    return v;
  }
};
