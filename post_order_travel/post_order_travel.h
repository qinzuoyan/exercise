#ifndef  __POST_ORDER_TRAVEL_H_
#define  __POST_ORDER_TRAVEL_H_

struct Node
{
    Node* lchild;
    Node* rchild;
    int data;
};

void post_order_travel(Node* root, void(*visitor)(Node*));

#endif  //__POST_ORDER_TRAVEL_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
