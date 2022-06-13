#include <cstdlib>
#include <deque>
#include <iostream>
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
  TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode *root) {
    if (!root) return "[]";
    deque<TreeNode *> d;
    deque<TreeNode *> all;
    d.push_back(root);
    all.push_back(root);
    while (!d.empty()) {
      TreeNode *n = d.front();
      d.pop_front();
      all.push_back(n->left);
      all.push_back(n->right);
      if (n->left) d.push_back(n->left);
      if (n->right) d.push_back(n->right);
    }
    ostringstream oss;
    oss << "[";
    int null_num = 0;
    for (TreeNode *n : all) {
      if (n) {
        if (null_num > 0) {
          for (int i = 0; i < null_num; i++) oss << "null,";
          null_num = 0;
        }
        oss << n->val << ",";
      } else {
        null_num++;
      }
    }
    string s = oss.str();
    s[s.size() - 1] = ']';
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    trimString(data, " ");
    if (data.size() < 2 || data[0] != '[' || data[data.size() - 1] != ']')
      return nullptr;
    data = data.substr(1, data.size() - 2);
    data = trimString(data, " ");
    if (data.empty()) return nullptr;
    vector<string> sv;
    split(data, sv, ',');
    if (sv.empty()) return nullptr;
    TreeNode *root = new TreeNode(atoi(trimString(sv[0], " ").c_str()));
    deque<TreeNode *> d;
    d.push_back(root);
    bool fill_left = true;
    size_t i = 0;
    while (++i < sv.size() && !d.empty()) {
      string &s = trimString(sv[i], " ");
      TreeNode *n = nullptr;
      if (s != "null") {
        n = new TreeNode(atoi(s.c_str()));
        d.push_back(n);
      }
      TreeNode *t = d.front();
      if (fill_left) {
        t->left = n;
        fill_left = false;
      } else {
        t->right = n;
        d.pop_front();
        fill_left = true;
      }
    }
    return root;
  }

 private:
  void split(const string &s, vector<string> &sv, char delim) {
    sv.clear();
    std::istringstream iss(s);
    std::string temp;
    while (std::getline(iss, temp, delim)) sv.emplace_back(std::move(temp));
  }

  string &leftTrim(string &str, const string &chars) {
    str.erase(0, str.find_first_not_of(chars));
    return str;
  }

  string &rightTrim(string &str, const string &chars) {
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
  }

  string &trimString(string &str, const string &chars) {
    return leftTrim(rightTrim(str, chars), chars);
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
