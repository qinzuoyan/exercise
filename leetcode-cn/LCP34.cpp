#include <vector>
#include <cstring>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  void run(TreeNode* n, int* a, int k) {
    memset(a, 0, sizeof(int) * (k + 1));
    if (n == nullptr) return;
    int a1[k + 1], a2[k + 1];
    run(n->left, a1, k);
    run(n->right, a2, k);
    for (int i = 0; i <= k; i++) {
      for (int j = 0; j <= k; j++) {
        a[0] = max(a[0], a1[i] + a2[j]);
        if (i + j < k) a[i + j + 1] = max(a[i + j + 1], a1[i] + a2[j] + n->val);
      }
    }
  }
  int maxValue(TreeNode* root, int k) {
    int a[k + 1];
    run(root, a, k);
    int m = 0;
    for (int i = 0; i <= k; i++)
      if (a[i] > m) m = a[i];
    return m;
  }
};
