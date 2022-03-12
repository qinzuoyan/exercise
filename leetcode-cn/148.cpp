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
    // refer to problem 21
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode *r, *t;
        if (list1->val < list2->val) {
            r = t = list1;
            list1 = list1->next;
        }
        else {
            r = t = list2;
            list2 = list2->next;
        }
        while (list1 && list2) {
            if (list1->val < list2->val) {
                t->next = list1;
                t = list1;
                list1 = list1->next;
            }
            else {
                t->next = list2;
                t = list2;
                list2 = list2->next;
            }
        }
        if (list1)
            t->next = list1;
        if (list2)
            t->next = list2;
        return r;
    }

    ListNode* sortList(ListNode* head, int n) {
        if (n == 1) return head;
        int m = n / 2;
        ListNode* left = head;
        ListNode* rightPre = head;
        int i = m;
        while (--i)
            rightPre = rightPre->next;
        ListNode* right = rightPre->next;
        rightPre->next = nullptr;
        ListNode* leftSort = sortList(left, m);
        ListNode* rightSort = sortList(right, n-m);
        return mergeTwoLists(leftSort, rightSort);
    }

    ListNode* sortList(ListNode* head) {
        if (!head) return nullptr;
        int n = 0;
        ListNode* t = head;
        while (t) {
            n++;
            t = t->next;
        }
        return sortList(head, n);
    }
};

