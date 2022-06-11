#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Encrypter {
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

  void destroyTrie(TrieNode *trie) {
    if (trie == nullptr) return;
    for (int i = 0; i < 26; ++i) {
      if (trie->children[i]) destroyTrie(trie->children[i]);
    }
    delete trie;
  }

  static const int CN = 26;
  string ctov[CN];
  map<string, string> vtoc;
  TrieNode *trie;

 public:
  Encrypter(vector<char> &keys, vector<string> &values,
            vector<string> &dictionary) {
    int n = keys.size();
    for (int i = 0; i < n; ++i) {
      ctov[keys[i] - 'a'] = values[i];
      vtoc[values[i]].push_back(keys[i]);
    }
    trie = buildTrie(dictionary);
  }

  ~Encrypter() { destroyTrie(trie); }

  string encrypt(string word1) {
    string r;
    for (char c : word1) r += ctov[c - 'a'];
    return r;
  }

  int decrypt(string word2) {
    int n = word2.size(), i = 0;
    vector<TrieNode *> trie_nodes = {trie};
    while (i < n) {
      vector<TrieNode *> new_trie_nodes;
      const string &clist = vtoc[word2.substr(i, 2)];
      for (TrieNode *t : trie_nodes) {
        for (char c : clist) {
          if (t->children[c - 'a']) {
            new_trie_nodes.push_back(t->children[c - 'a']);
          }
        }
      }
      new_trie_nodes.swap(trie_nodes);
      i += 2;
    }
    int r = 0;
    for (TrieNode *t : trie_nodes) {
      if (t->is_word) ++r;
    }
    return r;
  }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
