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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) return nullptr;
    ListNode *p = headA;
    int n = 0;
    while (p) {
      p = p->next;
      n++;
    }
    p = headB;
    while (p) {
      p = p->next;
      n--;
    }
    if (n > 0) {
      while (n != 0) {
        headA = headA->next;
        n--;
      }
    } else {
      while (n != 0) {
        headB = headB->next;
        n++;
      }
    }
    while (headA && headB && headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }
    return headA == headB ? headA : nullptr;
  }
};
