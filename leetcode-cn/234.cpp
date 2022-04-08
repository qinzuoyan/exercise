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
  bool isPalindrome(ListNode *head) {
    if (head->next == nullptr) return true;
    int n, i;
    ListNode *p, *h, *q, *t;
    n = 0;
    p = head;
    while (p) {
      n++;
      p = p->next;
    }
    i = n / 2;
    p = head;
    h = nullptr;
    while (i > 0) {
      q = p;
      p = p->next;
      q->next = h;
      h = q;
      i--;
    }
    q = p;
    t = h;
    if (n % 2 == 1) p = p->next;
    while (p && p->val == h->val) {
      p = p->next;
      h = h->next;
    }
    bool r = (p == nullptr);
    p = t;
    head = nullptr;
    while (p) {
      h = p;
      p = p->next;
      h->next = head;
      head = h;
    }
    t->next = q;
    return r;
  }
};
