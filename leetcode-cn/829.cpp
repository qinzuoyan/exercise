class Solution {
 public:
  int consecutiveNumbersSum(int n) {
    int r = 1;
    for (int i = 2; n / i >= (i + 1) / 2; ++i) {
      if (i & 1) {
        if (n % i == 0) r++;
      } else {
        if (n % i == (i >> 1)) r++;
      }
    }
    return r;
  }
};
