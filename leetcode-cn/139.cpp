#include <cstring>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  bool is_word;
  TrieNode* children[26];
  TrieNode() : is_word(false) { memset(children, 0, sizeof(children)); }
};

class Solution {
 public:
  TrieNode* buildTrie(const vector<string>& dict) {
    TrieNode* root = new TrieNode();
    for (const string& s : dict) {
      TrieNode* n = root;
      for (char c : s) {
        size_t i = c - 'a';
        if (n->children[i] == nullptr) n->children[i] = new TrieNode();
        n = n->children[i];
      }
      n->is_word = true;
    }
    return root;
  }

  bool wordBreak(const string& s, size_t startpos, vector<int>& vec,
                 TrieNode* trie) {
    if (startpos >= s.size()) return true;
    if (vec[startpos] != 0) return vec[startpos] == 1 ? true : false;
    TrieNode* n = trie;
    size_t p = startpos;
    while (n && p < s.size()) {
      size_t i = s[p] - 'a';
      n = n->children[i];
      p++;
      if (n && n->is_word && wordBreak(s, p, vec, trie)) {
        vec[startpos] = 1;
        return true;
      }
    }
    vec[startpos] = -1;
    return false;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    TrieNode* trie = buildTrie(wordDict);
    vector<int> vec(
        s.size());  // -1 means false, 1 means true, 0 means not processed.
    return wordBreak(s, 0, vec, trie);
  }
};
