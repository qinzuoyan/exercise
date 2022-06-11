/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  void deleteNode(ListNode *node) {
    if (node) {
      node->val = node->next->val;
      node->next = node->next->next;
    }
  }
};
