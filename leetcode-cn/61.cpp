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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !k) {
            return head;
        }
        ListNode* p = head;
        int i = k;
        while (p && i) {
            p = p->next;
            i--;
        }
        if (!p) {
            return i ? rotateRight(head, k % (k - i)) : head;
        }
        ListNode* q = head;
        while (p->next) {
            p = p->next;
            q = q->next;
        }
        p->next = head;
        head = q->next;
        q->next = nullptr;
        return head;
    }
};
