class Solution {
 public:
  int trailingZeroes(int n) {
    int k = 0;
    for (int i = 1; i <= n; i++) {
      int j = i;
      while (j % 5 == 0) {
        j /= 5;
        k++;
      }
    }
    return k;
  }
};
