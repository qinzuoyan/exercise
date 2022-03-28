#include <vector>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> r;
        if (!root) {
            return r;
        }
        vector<int> v;
        stack<TreeNode*> s, s1;
        s.push(root);
        int d = 1;
        while (!s.empty()) {
            while (!s.empty()) {
                TreeNode* n = s.top();
                v.push_back(n->val);
                if (d) {
                    if (n->left) s1.push(n->left);
                    if (n->right) s1.push(n->right);
                }
                else {
                    if (n->right) s1.push(n->right);
                    if (n->left) s1.push(n->left);
                }
                s.pop();
            }
            s = move(s1);
            r.emplace_back(move(v));
            d ^= 1;
        }
        return r;
    }
};
