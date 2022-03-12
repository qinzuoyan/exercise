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
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* a = head;
        ListNode* b = head;
        while (a && b) {
            b = b->next;
            if (b == a) return true;
            if (b) b = b->next;
            if (b == a) return true;
            a = a->next;
        }
        return false;
    }
};
