#include <cstring>
using namespace std;

class Solution {
 public:
  int uniquePaths(int m, int n) {
    int a[m * n];
    memset(a, 0, sizeof(int) * m * n);
    a[0] = 1;
    return uniquePaths(a, n, m - 1, n - 1);
  }
  int uniquePaths(int* a, int n, int i, int j) {
    int p = i * n + j;
    if (a[p] > 0) return a[p];
    int s = 0;
    if (i > 0) s += uniquePaths(a, n, i - 1, j);
    if (j > 0) s += uniquePaths(a, n, i, j - 1);
    a[p] = s;
    return s;
  }
};
