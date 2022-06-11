#include <algorithm>
#include <vector>
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
  vector<int> reversePrint(ListNode *head) {
    vector<int> r;
    if (head) {
      while (head) {
        r.push_back(head->val);
        head = head->next;
      }
      std::reverse(r.begin(), r.end());
    }
    return r;
  }
};
