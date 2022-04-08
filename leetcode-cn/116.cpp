#include <deque>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (!root) return root;
    deque<Node*> d, d1;
    d.push_back(root);
    while (!d.empty()) {
      while (!d.empty()) {
        Node* n = d.front();
        d.pop_front();
        n->next = d.empty() ? nullptr : d.front();
        if (n->left) d1.push_back(n->left);
        if (n->right) d1.push_back(n->right);
      }
      d = move(d1);
    }
    return root;
  }
};
