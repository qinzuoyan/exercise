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
    ListNode* reverseList(ListNode* head) {
        ListNode* p = head;
        head = nullptr;
        while (p) {
            ListNode* q = p->next;
            p->next = head;
            head = p;
            p = q;
        }
        return head;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) {
            return head;
        }
        ListNode* p = head, *lasttail = nullptr;
        head = nullptr;
        while (p) {
            ListNode* subhead = p, *subtail = nullptr;
            int i = k;
            while (p && i) {
                if (i == 1) {
                    subtail = p;
                }
                p = p->next;
                i--;
            }
            if (subtail != nullptr) {
                subtail->next = nullptr;
                subtail = subhead;
                subhead = reverseList(subhead);
            }
            if (head == nullptr) {
                head = subhead;
            }
            else {
                lasttail->next = subhead;
            }
            lasttail = subtail;
        }
        return head;
    }
};
