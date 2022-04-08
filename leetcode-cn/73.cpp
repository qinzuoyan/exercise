#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    int a[m], b[n];
    memset(a, 0, sizeof(int) * m);
    memset(b, 0, sizeof(int) * n);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!matrix[i][j]) {
          a[i] = 1;
          b[j] = 1;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] && (a[i] || b[j])) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};
