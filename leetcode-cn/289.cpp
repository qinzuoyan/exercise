#include <vector>
using namespace std;

class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = board[0].size();
    vector<vector<int>> r = board;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int c = 0;
        if (i > 0 && board[i - 1][j]) c++;
        if (i > 0 && j > 0 && board[i - 1][j - 1]) c++;
        if (i > 0 && j < n - 1 && board[i - 1][j + 1]) c++;
        if (j > 0 && board[i][j - 1]) c++;
        if (j < n - 1 && board[i][j + 1]) c++;
        if (i < m - 1 && board[i + 1][j]) c++;
        if (i < m - 1 && j > 0 && board[i + 1][j - 1]) c++;
        if (i < m - 1 && j < n - 1 && board[i + 1][j + 1]) c++;
        if (board[i][j] && (c < 2 || c > 3)) {
          r[i][j] = 0;
        } else if (!board[i][j] && c == 3) {
          r[i][j] = 1;
        }
      }
    }
    board.swap(r);
  }
};
