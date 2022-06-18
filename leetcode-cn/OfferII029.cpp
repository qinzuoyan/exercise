// Definition for a Node.
class Node {
 public:
  int val;
  Node* next;

  Node() {}

  Node(int _val) {
    val = _val;
    next = nullptr;
  }

  Node(int _val, Node* _next) {
    val = _val;
    next = _next;
  }
};

class Solution {
 public:
  Node* insert(Node* head, int insertVal) {
    if (!head) {
      Node* n = new Node(insertVal);
      n->next = n;
      return n;
    }
    Node* p = head;
    while (p->next && p->next != p) {
      int k = p->next->val;
      if (k > p->val && insertVal >= p->val && insertVal <= k)
        break;
      else if (k < p->val && (insertVal >= p->val || insertVal <= k))
        break;
      else if (insertVal == k || p->next == head)
        break;
      p = p->next;
    }
    Node* n = new Node(insertVal, p->next);
    p->next = n;
    return head;
  }
};
