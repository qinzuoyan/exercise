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
    if (!root || !root->left) return root;
    Node* l = connect(root->left);
    Node* r = connect(root->right);
    while (l) {
      l->next = r;
      l = l->right;
      r = r->left;
    }
    return root;
  }
};
