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
  bool hasCycle(ListNode *head) {
    if (!head) return false;
    ListNode *a = head, *b = head;
    do {
      if (!b->next || !b->next->next) return false;
      a = a->next;
      b = b->next->next;
    } while (a != b);
    return true;
  }
};
