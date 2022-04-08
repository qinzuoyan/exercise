#include <unordered_set>
using namespace std;

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
    unordered_set<ListNode *> s;
    while (headA) {
      s.insert(headA);
      headA = headA->next;
    }
    while (headB) {
      if (s.find(headB) != s.end()) return headB;
      headB = headB->next;
    }
    return nullptr;
  }
};
