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
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *constructMaximumBinaryTree(vector<int> &nums, int i, int j) {
    if (i > j)
      return nullptr;
    if (i == j)
      return new TreeNode(nums[i]);
    int m = i;
    for (int x = i + 1; x <= j; ++x) {
      if (nums[x] > nums[m])
        m = x;
    }
    return new TreeNode(nums[m], constructMaximumBinaryTree(nums, i, m - 1),
                        constructMaximumBinaryTree(nums, m + 1, j));
  }
  TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
    return constructMaximumBinaryTree(nums, 0, nums.size() - 1);
  }
};
