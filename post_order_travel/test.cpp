#include "post_order_travel.h"
#include <stdio.h>

Node* new_node(Node* l, Node* r, int d)
{
    Node* n = new Node;
    n->lchild = l;
    n->rchild = r;
    n->data = d;
    return n;
}

// null root
// result: 
Node* case_1()
{
    return NULL;
}

// one node: 1
// result: 1
Node* case_2()
{
    return new_node(NULL, NULL, 1);
}

// left link: 1->5->2->4
// result: 4251
Node* case_3()
{
    Node* n_4 = new_node(NULL, NULL, 4);
    Node* n_2 = new_node(n_4, NULL, 2);
    Node* n_5 = new_node(n_2, NULL, 5);
    Node* n_1 = new_node(n_5, NULL, 1);
    return n_1;
}

// right link: 1->5->2->4
// result: 4251
Node* case_4()
{
    Node* n_4 = new_node(NULL, NULL, 4);
    Node* n_2 = new_node(NULL, n_4, 2);
    Node* n_5 = new_node(NULL, n_2, 5);
    Node* n_1 = new_node(NULL, n_5, 1);
    return n_1;
}

// full
//       1
//    7     2
//  5  3  4   6
//  result: 5374621
Node* case_5()
{
    Node* n_5 = new_node(NULL, NULL, 5);
    Node* n_3 = new_node(NULL, NULL, 3);
    Node* n_4 = new_node(NULL, NULL, 4);
    Node* n_6 = new_node(NULL, NULL, 6);
    Node* n_7 = new_node(n_5, n_3, 7);
    Node* n_2 = new_node(n_4, n_6, 2);
    Node* n_1 = new_node(n_7, n_2, 1);
    return n_1;
}

// full
//       1
//    7     2
//     3  4    
//  result: 37421
Node* case_6()
{
    Node* n_3 = new_node(NULL, NULL, 3);
    Node* n_4 = new_node(NULL, NULL, 4);
    Node* n_7 = new_node(NULL, n_3, 7);
    Node* n_2 = new_node(n_4, NULL, 2);
    Node* n_1 = new_node(n_7, n_2, 1);
    return n_1;
}

void visit(Node* n)
{
    printf("%d", n->data);
}

int main()
{
    post_order_travel(case_1(), &visit);
    printf("\n");
    post_order_travel(case_2(), &visit);
    printf("\n");
    post_order_travel(case_3(), &visit);
    printf("\n");
    post_order_travel(case_4(), &visit);
    printf("\n");
    post_order_travel(case_5(), &visit);
    printf("\n");
    post_order_travel(case_6(), &visit);
    printf("\n");
}


/* vim: set ts=4 sw=4 sts=4 tw=100 */
