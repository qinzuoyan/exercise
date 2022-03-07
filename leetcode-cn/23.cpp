#include <vector>
using namespace std;

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

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;
        if (lists.size() == 1) return lists[0];
        for (size_t i = 1; i < lists.size(); i++) {
            lists[i] = mergeTwoLists(lists[i-1], lists[i]);
        }
        return lists[lists.size() - 1];
    }
};
