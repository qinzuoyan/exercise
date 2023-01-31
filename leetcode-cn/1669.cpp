
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
    ListNode *x = list1, *before_a = nullptr, *at_a = nullptr, *at_b = nullptr, *after_b = nullptr;
    int i = 0;
    while (i + 1 < a) {
      x = x->next;
      ++i;
    }
    before_a = x;
    at_a = x->next;
    while (i < b) {
      x = x->next;
      ++i;
    }
    at_b = x;
    after_b = at_b->next;

    at_b->next = nullptr;
    x = at_a;
    while (x) {
      ListNode* p = x;
      x = x->next;
      delete p;
    }

    before_a->next = list2;
    while (list2->next) {
      list2 = list2->next;
    }
    list2->next = after_b;
    return list1;
  }
};
