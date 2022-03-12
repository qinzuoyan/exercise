#include <climits>
#include <stack>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* n = root;
        while (n) {
            s.push(n);
            n = n->left;
        }
        int first = 1;
        int prev;
        while (!s.empty()) {
            TreeNode* t = s.top();
            if (first)
                first = 0;
            else if (t->val <= prev)
                return false;
            prev = t->val;
            s.pop();
            n = t->right;
            while (n) {
                s.push(n);
                n = n->left;
            }
        }
        return true;
    }
};
