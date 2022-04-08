#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size(), n = matrix[0].size(), max = 0;
    int a[m][n];
    memset(a, 0, sizeof(int) * m * n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == '1') {
          if (i == 0 || j == 0) {
            a[i][j] = 1;
          } else {
            a[i][j] = min(min(a[i - 1][j], a[i - 1][j - 1]), a[i][j - 1]) + 1;
          }
          if (a[i][j] > max) {
            max = a[i][j];
          }
        }
      }
    }
    return max * max;
  }
};
