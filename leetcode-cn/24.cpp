/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode *swapPairs(ListNode *head) {
    ListNode h(0, head);
    ListNode *a = &h;
    while (a->next && a->next->next) {
      ListNode *x = a->next;
      ListNode *y = x->next;
      ListNode *z = y->next;
      a->next = y;
      y->next = x;
      x->next = z;
      a = x;
    }
    return h.next;
  }
};
