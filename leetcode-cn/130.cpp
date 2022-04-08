#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  void solve(vector<vector<char>>& board) {
    int m = board.size(), n = board[0].size();
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'x';
        }
      }
    }
    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O') trans(board, m, n, i, 0);
      if (board[i][n - 1] == 'O') trans(board, m, n, i, n - 1);
    }
    for (int j = 0; j < n; j++) {
      if (board[0][j] == 'O') trans(board, m, n, 0, j);
      if (board[m - 1][j] == 'O') trans(board, m, n, m - 1, j);
    }
    for (int i = 1; i < m - 1; i++) {
      for (int j = 1; j < n - 1; j++) {
        if (board[i][j] == 'x') {
          board[i][j] = 'X';
        }
      }
    }
  }

  void trans(vector<vector<char>>& b, int m, int n, int i, int j) {
    stack<pair<int, int>> q;
    q.emplace(i, j);
    while (!q.empty()) {
      i = q.top().first;
      j = q.top().second;
      q.pop();
      if (i > 0 && b[i - 1][j] == 'x') {
        b[i - 1][j] = 'O';
        q.emplace(i - 1, j);
      }
      if (j > 0 && b[i][j - 1] == 'x') {
        b[i][j - 1] = 'O';
        q.emplace(i, j - 1);
      }
      if (i < m - 1 && b[i + 1][j] == 'x') {
        b[i + 1][j] = 'O';
        q.emplace(i + 1, j);
      }
      if (j < n - 1 && b[i][j + 1] == 'x') {
        b[i][j + 1] = 'O';
        q.emplace(i, j + 1);
      }
    }
  }
};
