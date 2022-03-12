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
    // @ret maxDepth >= 0
    int maxPathSum(TreeNode* root, int* maxDepth) {
        int maxRet = root->val;
        int maxRoot = root->val;
        *maxDepth = root->val > 0 ? root->val : 0;
        if (root->left) {
            int maxDepthLeft;
            int maxLeft = maxPathSum(root->left, &maxDepthLeft);
            maxRet = max(maxRet, maxLeft);
            maxRoot += maxDepthLeft;
            if (root->val + maxDepthLeft > *maxDepth)
                *maxDepth = root->val + maxDepthLeft;
        }
        if (root->right) {
            int maxDepthRight;
            int maxRight= maxPathSum(root->right, &maxDepthRight);
            maxRet = max(maxRet, maxRight);
            maxRoot += maxDepthRight;
            if (root->val + maxDepthRight > *maxDepth)
                *maxDepth = root->val + maxDepthRight;
        }
        maxRet = max(maxRet, maxRoot);
        return maxRet;
    }
    int maxPathSum(TreeNode* root) {
        int n;
        return maxPathSum(root, &n);
    }
};
