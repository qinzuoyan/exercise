#include <unordered_map>
using namespace std;

/*
// Definition for a Node.
*/
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) {
      return head;
    }
    unordered_map<Node*, Node*> m;
    Node *h = nullptr, *pre = nullptr, *cur = head;
    while (cur) {
      Node* n = new Node(cur->val);
      if (pre) {
        pre->next = n;
      } else {
        h = n;
      }
      pre = n;
      m[cur] = n;
      cur = cur->next;
    }
    cur = h, pre = head;
    while (cur) {
      cur->random = m[pre->random];
      cur = cur->next;
      pre = pre->next;
    }
    return h;
  }
};
