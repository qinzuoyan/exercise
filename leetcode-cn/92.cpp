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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || !head->next || left >= right)
            return head;

        ListNode fake(0, head);

        ListNode* cur = &fake;
        int c = 1;
        while (c < left) {
            cur = cur->next;
            c++;
        }

        ListNode* rprev= cur;
        ListNode* rtail = cur->next;
        rprev->next = nullptr;
        cur = rtail;
        int n = right - left + 1;
        c = 0;
        while (c < n) {
            ListNode* t = cur->next;
            cur->next = rprev->next;
            rprev->next = cur;
            cur = t;
            c++;
        }

        rtail->next = cur;
        return fake.next;
    }
};
