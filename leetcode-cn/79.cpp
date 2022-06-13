#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool exist(vector<vector<char>> &board, size_t i, size_t j,
             const string &word, size_t pos) {
    if (board[i][j] < 0 || board[i][j] != word[pos]) return false;
    board[i][j] = -board[i][j];
    if (pos == word.size() - 1) return true;
    if (i > 0 && exist(board, i - 1, j, word, pos + 1)) return true;
    if (i < board.size() - 1 && exist(board, i + 1, j, word, pos + 1))
      return true;
    if (j > 0 && exist(board, i, j - 1, word, pos + 1)) return true;
    if (j < board[0].size() - 1 && exist(board, i, j + 1, word, pos + 1))
      return true;
    board[i][j] = -board[i][j];
    return false;
  }
  bool exist(vector<vector<char>> &board, string word) {
    size_t m = board.size();
    size_t n = board[0].size();
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        if (exist(board, i, j, word, 0)) {
          return true;
        }
      }
    }
    return false;
  }
};
