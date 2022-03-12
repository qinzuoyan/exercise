#include <vector>
#include <stack>
#include <utility>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    // non-recursive algorithm
    vector<int> preorder(Node* root) {
        vector<int> out;
        if (!root) return out;
        stack<pair<Node*, size_t>> s;
        s.push(make_pair(root, 0));
        while (!s.empty()) {
            pair<Node*, size_t>& t = s.top();
            Node* n = t.first;
            size_t p = t.second;
            if (p == 0) // preorder visit
                out.push_back(n->val);
            if (p < n->children.size()) {
                t.second++; // modify t before push new item
                if (n->children[p] != nullptr)
                    s.push(make_pair(n->children[p], 0));
            }
            else {
                s.pop();
            }
        }
        return out;
    }
};
