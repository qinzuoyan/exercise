class Solution {
 public:
  int mySqrt(int x) {
    int i = 0, j = (x > 46340 ? 46340 : x), mid, d;
    while (i < j) {
      mid = (i + j + 1) >> 1;
      d = mid * mid;
      if (d == x)
        return mid;
      else if (d > x) {
        j = mid - 1;
      } else {
        i = mid;
      }
    }
    return i;
  }
};
