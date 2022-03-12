#include <algorithm>
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
    // like problem 124
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int x;
        return diameterOfBinaryTree(root, &x);
    }

    // @ret maxDepth >= 0
    int diameterOfBinaryTree(TreeNode* root, int* maxDepth) {
        *maxDepth = 0;
        int retMax = 0;
        int curMax = 0;
        if (root->left) {
            int x;
            int y = diameterOfBinaryTree(root->left, &x);
            *maxDepth = max(*maxDepth, x + 1);
            retMax = max(retMax, y);
            curMax += x + 1;
        }
        if (root->right) {
            int x;
            int y = diameterOfBinaryTree(root->right, &x);
            *maxDepth = max(*maxDepth, x + 1);
            retMax = max(retMax, y);
            curMax += x + 1;
        }
        retMax = max(retMax, curMax);
        return retMax;
    }
};
