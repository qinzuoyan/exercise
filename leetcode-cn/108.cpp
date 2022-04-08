#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return sortedArrayToBST(&nums[0], nums.size());
  }

  TreeNode* sortedArrayToBST(int* nums, int n) {
    return n == 0 ? nullptr
                  : new TreeNode(
                        nums[n >> 1], sortedArrayToBST(nums, n >> 1),
                        sortedArrayToBST(nums + 1 + (n >> 1), (n - 1) >> 1));
    ;
  }
};
