#include <vector>
using namespace std;

// Definition for a Node.
class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

class Solution {
 public:
  void preorder(Node* root, vector<int>& out) {
    if (root) {
      out.push_back(root->val);
      for (Node* n : root->children) {
        if (n) preorder(n, out);
      }
    }
  }

  // recursive algorithm
  vector<int> preorder(Node* root) {
    vector<int> out;
    preorder(root, out);
    return out;
  }
};
