#include <cassert>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (root == nullptr) return "";
    ostringstream oss;
    oss << root->val << ';';
    vector<TreeNode *> v1;
    vector<TreeNode *> v2;
    v1.push_back(root);
    while (v1.size()) {
      int n = v1.size(), c = 0, z = 0;
      for (int i = 0; i < n; ++i) {
        TreeNode *n = v1[i];
        if (n->left) {
          if (c > 0) oss << ',';
          if (z > 0) {
            oss << 'n';
            if (z > 1) oss << z;
            oss << ',';
            z = 0;
          }
          oss << n->left->val;
          v2.push_back(n->left);
          ++c;
        } else {
          ++z;
        }
        if (n->right) {
          if (c > 0) oss << ',';
          if (z > 0) {
            oss << 'n';
            if (z > 1) oss << z;
            oss << ',';
            z = 0;
          }
          oss << n->right->val;
          v2.push_back(n->right);
          ++c;
        } else {
          ++z;
        }
      }
      if (c > 0) oss << ';';
      v1.swap(v2);
      v2.clear();
    }
    return oss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty()) return nullptr;
    const char *p = data.c_str(), *end = data.c_str() + data.size();
    char *endptr = nullptr;
    TreeNode *root = new TreeNode(strtol(p, &endptr, 10));
    p = endptr;
    vector<TreeNode *> v1;
    vector<TreeNode *> v2;
    v2.push_back(root);
    int i = 0;
    while (p != end) {
      if (*p == ',') {
        ++p;
      } else if (isdigit(*p)) {
        TreeNode *n = new TreeNode(strtol(p, &endptr, 10));
        p = endptr;
        if (i & 1)
          v1[i >> 1]->right = n;
        else
          v1[i >> 1]->left = n;
        v2.push_back(n);
        ++i;
      } else if (*p == 'n') {
        ++p;
        if (isdigit(*p)) {
          i += strtol(p, &endptr, 10);
          p = endptr;
        } else {
          ++i;
        }
      } else if (*p == ';') {
        v1.swap(v2);
        v2.clear();
        i = 0;
        ++p;
      } else {
        assert(false);
        ++p;
      }
    }
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
