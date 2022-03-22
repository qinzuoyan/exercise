#include <unordered_set>
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
    bool findTarget(unordered_set<int>& m, TreeNode* n, int k) {
        if (n == nullptr)
            return false;
        if (m.find(k - n->val) != m.end())
            return true;
        m.emplace(n->val);
        if (findTarget(m, n->left, k))
            return true;
        if (findTarget(m, n->right, k))
            return true;
        return false;
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> m;
        return findTarget(m, root, k);
    }
};
