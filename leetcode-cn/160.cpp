#include <stack>
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
        if (!headA || !headB)
            return nullptr;
        stack<ListNode*> sa, sb;
        ListNode *a = headA, *b = headB;
        while (a) {
            sa.push(a);
            a = a->next;
        }
        while (b) {
            sb.push(b);
            b = b->next;
        }
        ListNode* p = nullptr;
        while (!sa.empty() && !sb.empty() && sa.top() == sb.top()) {
            p = sa.top();
            sa.pop();
            sb.pop();
        }
        return p;
    }
};
