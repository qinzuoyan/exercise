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
  ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;
    ListNode *a = head, *b = head;
    do {
      if (!b->next || !b->next->next) return nullptr;
      a = a->next;
      b = b->next->next;
    } while (a != b);
    a = head;
    while (a != b) {
      a = a->next;
      b = b->next;
    }
    return a;
  }
};
