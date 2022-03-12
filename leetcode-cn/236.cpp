#include <deque>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p == q) return p;
        bool pFound = false, qFound = false;
        deque<TreeNode*> s, pTrace, qTrace;
        deque<bool> b;
        TreeNode* n = root;
        while (n || !s.empty()) {
            while (n) {
                s.push_back(n);
                b.push_back(false);

                // preorder visit
                if (!pFound && p == n) {
                    pFound = true;
                    pTrace = s;
                }
                if (!qFound && q == n) {
                    qFound = true;
                    qTrace = s;
                }
                if (pFound && qFound)
                    break;

                n = n->left;
            }
            if (!s.empty()) {
                if (b.back()) {
                    s.pop_back();
                    b.pop_back();
                }
                else {
                    b.back() = true;
                    n = s.back()->right;
                }
            }
        }
        TreeNode* r = nullptr;
        while (!pTrace.empty() && !qTrace.empty()
                && pTrace.front() == qTrace.front()) {
            r = pTrace.front();
            pTrace.pop_front();
            qTrace.pop_front();
        }
        return r;
    }
};
