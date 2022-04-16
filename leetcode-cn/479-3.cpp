class Solution {
 public:
  int largestPalindrome(int n) {
    if (n == 1) {
      return 9;
    }
    int m = 1;
    for (int i = 0; i < n; i++) {
      m *= 10;
    }
    m -= 1;
    long long r = 0;
    for (int i = m; i > 0; --i) {
      long long c = i;
      int k = i;
      while (k) {
        c = c * 10 + k % 10;
        k /= 10;
      }
      for (long long j = m; j * j >= c; --j) {
        if (c % j == 0) {
          r = c;
          break;
        }
      }
      if (r > 0) break;
    }
    return r % 1337;
  }
};
