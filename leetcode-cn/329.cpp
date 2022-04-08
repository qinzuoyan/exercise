#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<vector<int>>& matrix, vector<vector<int>>& longest,
             size_t i, size_t j) {
    if (longest[i][j] > 0) return longest[i][j];
    int m = 0, c = matrix[i][j];
    if (i > 0 && matrix[i - 1][j] > c)
      m = max(m, search(matrix, longest, i - 1, j));
    if (i < matrix.size() - 1 && matrix[i + 1][j] > c)
      m = max(m, search(matrix, longest, i + 1, j));
    if (j > 0 && matrix[i][j - 1] > c)
      m = max(m, search(matrix, longest, i, j - 1));
    if (j < matrix[0].size() - 1 && matrix[i][j + 1] > c)
      m = max(m, search(matrix, longest, i, j + 1));
    longest[i][j] = m + 1;
    return longest[i][j];
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    size_t m = matrix.size();
    size_t n = matrix[0].size();
    int max = 0;
    vector<vector<int>> longest(m, vector<int>(n));
    for (size_t i = 0; i < m; i++) {
      for (size_t j = 0; j < n; j++) {
        int r = search(matrix, longest, i, j);
        if (r > max) {
          max = r;
        }
      }
    }
    return max;
  }
};
