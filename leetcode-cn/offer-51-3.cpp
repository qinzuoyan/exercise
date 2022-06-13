#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int mergeSort(int *a, int i, int j, int *b) {
    if (i == j) {
      return 0;
    }
    int m = (i + j) >> 1;
    int r = mergeSort(a, i, m, b) + mergeSort(a, m + 1, j, b);
    int x = i, xn = m - i + 1, y = m + 1, z = 0;
    while (x <= m && y <= j) {
      if (a[x] <= a[y]) {
        b[z++] = a[x++];
        xn--;
      } else {  // a[x] > a[y]
        r += xn;
        b[z++] = a[y++];
      }
    }
    if (xn > 0) {
      memcpy(b + z, a + x, sizeof(int) * xn);
      z += xn;
    }
    memcpy(a + i, b, sizeof(int) * z);
    return r;
  }

  // merge sort
  // O(nlog(n))
  int reversePairs(vector<int> &nums) {
    int n = nums.size();
    if (n <= 1) {
      return 0;
    }
    int t[n];
    return mergeSort(&nums[0], 0, n - 1, t);
  }
};
