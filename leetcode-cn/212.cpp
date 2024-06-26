#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  struct TrieNode {
    const char *word;
    int word_count;
    TrieNode *children[26];
    TrieNode() : word(nullptr), word_count(0) {
      memset(children, 0, sizeof(children));
    }
  };

  TrieNode *buildTrie(const vector<string> &dict) {
    TrieNode *root = new TrieNode();
    for (const string &s : dict) {
      TrieNode *n = root;
      for (char c : s) {
        size_t i = c - 'a';
        if (n->children[i] == nullptr) n->children[i] = new TrieNode();
        n = n->children[i];
        n->word_count++;
      }
      n->word = s.data();
    }
    return root;
  }

  int find(vector<vector<char>> &board, TrieNode *trie, size_t i, size_t j,
           vector<string> &found) {
    if (board[i][j] < 0) {  // visited
      return 0;
    }
    int ci = board[i][j] - 'a';
    if (!trie->children[ci] || !trie->children[ci]->word_count) {
      return 0;
    }
    trie = trie->children[ci];
    int wc = 0;
    if (trie->word) {
      found.emplace_back(trie->word);
      trie->word = nullptr;
      wc++;
    }
    board[i][j] = -board[i][j];  // set visited
    if (i > 0) {
      wc += find(board, trie, i - 1, j, found);
    }
    if (i < board.size() - 1) {
      wc += find(board, trie, i + 1, j, found);
    }
    if (j > 0) {
      wc += find(board, trie, i, j - 1, found);
    }
    if (j < board[0].size() - 1) {
      wc += find(board, trie, i, j + 1, found);
    }
    board[i][j] = -board[i][j];  // set unvisited
    trie->word_count -= wc;
    return wc;
  }

  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    TrieNode *trie = buildTrie(words);
    size_t m = board.size(), n = board[0].size();
    vector<string> found;
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        find(board, trie, i, j, found);
      }
    }
    return found;
  }
};
