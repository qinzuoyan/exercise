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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return head;
        }
        ListNode *h1 = head, *h2 = head->next;
        ListNode *t1 = h1, *t2 = h2, *p = h2->next;
        int k = 2;
        while (p) {
            ++k;
            if (k & 1) {
                t1->next = p;
                t1 = p;
            }
            else {
                t2->next = p;
                t2 = p;
            }
            p = p->next;
        }
        t2->next = nullptr;
        t1->next = h2;
        return h1;
    }
};
