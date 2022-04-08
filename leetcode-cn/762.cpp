class Solution {
 public:
  int bitCount(int i) {
    int c = 0;
    while (i) {
      c++;
      i = i & (i - 1);
    }
    return c;
  }
  int countPrimeSetBits(int left, int right) {
    int a[20] = {1, 1, 0};
    for (int i = 2; i < 20; i++) {
      if (!a[i]) {
        for (int j = i + i; j < 20; j += i) {
          a[j] = 1;
        }
      }
    }
    int s = 0;
    for (int i = left; i <= right; i++) {
      if (!a[bitCount(i)]) {
        s++;
      }
    }
    return s;
  }
};
