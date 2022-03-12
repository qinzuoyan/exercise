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
    static int sSum;

    TreeNode* convertBST(TreeNode* root) {
        sSum = 0;
        travelTree(root);
        return root;
    }

    void travelTree(TreeNode* root) {
        if (!root) return;
        travelTree(root->right);
        sSum += root->val;
        root->val = sSum;
        travelTree(root->left);
    }
};

int Solution::sSum = 0;
