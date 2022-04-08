#include <cstring>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  struct TrieNode {
    int word_id;  // -1 means not word
    int word_count;
    int children[26];  // -1 means no child
    TrieNode() : word_id(-1), word_count(0) {
      memset(children, -1, sizeof(children));
    }
  };

  int buildTrie(vector<TrieNode>& trie, const vector<string>& dict) {
    int root = trie.size();
    trie.emplace_back();
    int m = dict.size();
    for (int id = 0; id < m; id++) {
      const string& s = dict[id];
      int n = root;
      for (char c : s) {
        size_t i = c - 'a';
        if (trie[n].children[i] == -1) {
          trie[n].children[i] = trie.size();
          trie.emplace_back();
        }
        n = trie[n].children[i];
        trie[n].word_count++;
      }
      trie[n].word_id = id;
    }
    return root;
  }

  int find(vector<vector<char>>& board, vector<TrieNode>& trie, int root,
           size_t i, size_t j, vector<int>& found) {
    if (board[i][j] < 0) {  // visited
      return 0;
    }
    TrieNode* tr = &trie[root];
    int ci = board[i][j] - 'a';
    if (tr->children[ci] == -1) {
      return 0;
    }
    root = tr->children[ci];
    tr = &trie[root];
    if (tr->word_count == 0) {
      return 0;
    }
    int wc = 0;
    if (tr->word_id >= 0) {
      found.push_back(tr->word_id);
      tr->word_id = -1;
      wc++;
    }
    board[i][j] = -board[i][j];  // set visited
    if (i > 0) {
      wc += find(board, trie, root, i - 1, j, found);
    }
    if (i < board.size() - 1) {
      wc += find(board, trie, root, i + 1, j, found);
    }
    if (j > 0) {
      wc += find(board, trie, root, i, j - 1, found);
    }
    if (j < board[0].size() - 1) {
      wc += find(board, trie, root, i, j + 1, found);
    }
    board[i][j] = -board[i][j];  // set unvisited
    tr->word_count -= wc;
    return wc;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    vector<int> found;
    vector<TrieNode> trie;
    int root = buildTrie(trie, words);
    size_t m = board.size(), n = board[0].size();
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        find(board, trie, root, i, j, found);
      }
    }
    vector<string> r;
    for (int id : found) {
      r.push_back(words[id]);
    }
    return r;
  }
};
