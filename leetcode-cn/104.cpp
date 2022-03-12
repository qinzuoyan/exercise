#include <vector>
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        vector<TreeNode*> a,b;
        a.push_back(root);
        int d = 0;
        while (!a.empty()) {
            d++;
            b.clear();
            for (size_t i = 0; i < a.size(); i++) {
                TreeNode* t = a[i];
                if (t->left) b.push_back(t->left);
                if (t->right) b.push_back(t->right);
            }
            a.swap(b);
        }
        return d;
    }
};
