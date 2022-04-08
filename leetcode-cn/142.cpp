#include <set>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    set<ListNode *> s;
    ListNode *n = head;
    while (n) {
      if (s.find(n) != s.end()) return n;
      s.insert(n);
      n = n->next;
    }
    return nullptr;
  }
};
