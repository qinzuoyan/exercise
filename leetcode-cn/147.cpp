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
  ListNode *insertionSortList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode h(0, head);
    ListNode *cur = head->next;
    head->next = nullptr;
    while (cur) {
      ListNode *newCur = cur->next;
      ListNode *n = &h;
      while (n->next && n->next->val < cur->val) n = n->next;
      cur->next = n->next;
      n->next = cur;
      cur = newCur;
    }
    return h.next;
  }

  ListNode *selectionSortList(ListNode *head) {
    ListNode *cur = head;
    while (cur) {
      ListNode *min = cur;
      ListNode *n = cur->next;
      while (n) {
        if (n->val < min->val) min = n;
        n = n->next;
      }
      if (cur != min) {
        // swap cur and min
        int t = cur->val;
        cur->val = min->val;
        min->val = t;
      }
      cur = cur->next;
    }
    return head;
  }
};
