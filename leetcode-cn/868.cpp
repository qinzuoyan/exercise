class Solution {
 public:
  int binaryGap(int n) {
    int last = -1, i = 0, m = 0, k = 1;
    while (n) {
      if (n & k) {
        if (last != -1 && i - last > m) {
          m = i - last;
        }
        last = i;
        n ^= k;
      }
      i++;
      k <<= 1;
    }
    return m;
  }
};
