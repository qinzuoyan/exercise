class Solution {
 public:
  int findTheWinner(int n, int k) {
    int a[n], h = 0, s = 0;
    for (int i = 0; i < n; ++i) a[i] = i + 1;
    while (n > 1) {
      s = (k + s - 1) % n;
      if (s == 0) {
        h = a[h];
      } else if (s == n - 1) {
        s = 0;
      } else {
        int p = h, t = s;
        while (--t > 0) p = a[p];
        a[p] = a[a[p]];
      }
      --n;
    }
    return h + 1;
  }
};
