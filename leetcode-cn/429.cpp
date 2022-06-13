#include <deque>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> r;
    if (!root) {
      return r;
    }
    deque<Node *> q;
    q.push_back(root);
    q.push_back(nullptr);
    r.push_back(vector<int>());
    while (q.size()) {
      Node *n = q.front();
      q.pop_front();
      if (n) {
        r.back().push_back(n->val);
        q.insert(q.end(), n->children.begin(), n->children.end());
      } else {
        if (q.size()) {
          r.push_back(vector<int>());
          q.push_back(nullptr);
        }
      }
    }
    return r;
  }
};
