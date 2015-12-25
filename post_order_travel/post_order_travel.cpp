#include "post_order_travel.h"
#include <stack>

struct StackNode {
    Node* ptr;
    int flag;
};

void post_order_travel(Node* root, void(*visitor)(Node*))
{
    std::stack<StackNode> s;
    Node* p = root;
    while (p || !s.empty()) {
        while (p) {
            StackNode x;
            x.ptr = p;
            x.flag = 0;
            s.push(x);
            p = p->lchild;
        }
        while (!s.empty() && s.top().flag == 1) {
            visitor(s.top().ptr);
            s.pop();
        }
        if (!s.empty()) {
            s.top().flag = 1;
            p = s.top().ptr->rchild;
        }
    }
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
