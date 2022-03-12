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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(&preorder[0], &inorder[0], preorder.size());
    }
    TreeNode* buildTree(int* preorder, int* inorder, int n) {
        if (n == 0) return nullptr;
        int v = *preorder;
        TreeNode* r = new TreeNode(v);
        if (n > 0) {
            int i = 0;
            while (i < n && inorder[i] != v) i++;
            r->left = buildTree(preorder + 1, inorder, i);
            r->right = buildTree(preorder + i + 1, inorder + i + 1, n - i - 1);
        }
        return r;
    }
};
