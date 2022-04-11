class Solution {
 public:
  int countNumbersWithUniqueDigits(int n) {
    int r = 1, m = 1;
    for (int i = 0; i < n; i++) {
      m *= 10;
    }
    for (int i = 1; i < m; i++) {
      int b = 0, j = i;
      while (j) {
        int k = 1 << (j % 10);
        if (k & b) {
          break;
        }
        b |= k;
        j /= 10;
      }
      if (j == 0) r++;
    }
    return r;
  }
};
