#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  struct TrieNode {
    bool is_word;
    TrieNode *children[26];
    TrieNode() : is_word(false) { memset(children, 0, sizeof(children)); }
  };

  TrieNode *buildTrie(const vector<string> &dict) {
    TrieNode *root = new TrieNode();
    for (const string &s : dict) {
      TrieNode *n = root;
      for (char c : s) {
        size_t i = c - 'a';
        if (n->children[i] == nullptr) n->children[i] = new TrieNode();
        n = n->children[i];
      }
      n->is_word = true;
    }
    return root;
  }

  bool wordBreak(vector<string> &r, string &t, const string &s, size_t startpos,
                 vector<int> &vec, TrieNode *trie) {
    if (startpos >= s.size()) {
      r.push_back(t);
      return true;
    }
    if (vec[startpos] == -1) {
      return false;
    }
    TrieNode *n = trie;
    size_t p = startpos;
    while (n && p < s.size()) {
      size_t i = s[p] - 'a';
      n = n->children[i];
      p++;
      if (n && n->is_word) {
        int l = 0;
        if (!t.empty()) {
          t.push_back(' ');
          l++;
        }
        t.append(s.data() + startpos, p - startpos);
        l += p - startpos;
        if (wordBreak(r, t, s, p, vec, trie)) {
          vec[startpos] = 1;
        }
        t.resize(t.size() - l);
      }
    }
    if (vec[startpos] == 0) {
      vec[startpos] = -1;
    }
    return vec[startpos] == 1;
  }

  vector<string> wordBreak(string s, vector<string> &wordDict) {
    TrieNode *trie = buildTrie(wordDict);
    vector<string> r;
    string t;
    vector<int> vec(
        s.size());  // -1 means false, 1 means true, 0 means not processed.
    wordBreak(r, t, s, 0, vec, trie);
    return r;
  }
};
