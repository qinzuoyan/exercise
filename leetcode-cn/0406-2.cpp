/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* getSuccessor(TreeNode* root, TreeNode* p, bool& found_p) {
    if (root == nullptr || p == nullptr) return nullptr;
    TreeNode* node = getSuccessor(root->left, p, found_p);
    if (node != nullptr) return node;
    if (found_p) return root;
    if (root == p) found_p = true;
    return getSuccessor(root->right, p, found_p);
  }

  TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p){
    bool found_p = false;
    return getSuccessor(root, p, found_p);
  }
};
