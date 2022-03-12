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
    void inorderTraversal(TreeNode* root, vector<int>& vec) {
        if (root) {
            inorderTraversal(root->left, vec);
            vec.push_back(root->val);
            inorderTraversal(root->right, vec);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        inorderTraversal(root, vec);
        return vec;
    }
};
