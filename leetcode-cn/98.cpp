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
    bool isValidBST(TreeNode* root, int* min, int* max) {
        *min = root->val;
        *max = root->val;
        if (root->left) {
            int left_min, left_max;
            if (!isValidBST(root->left, &left_min, &left_max))
                return false;
            if (left_max >= root->val)
                return false;
            *min = left_min;
        }
        if (root->right) {
            int right_min, right_max;
            if (!isValidBST(root->right, &right_min, &right_max))
                return false;
            if (right_min <= root->val)
                return false;
            *max = right_max;
        }
        return true;
    }

    bool isValidBST(TreeNode* root) {
        int min, max;
        return isValidBST(root, &min, &max);
    }
};
