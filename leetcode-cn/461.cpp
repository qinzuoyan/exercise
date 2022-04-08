class Solution {
 public:
  int hammingDistance(int x, int y) {
    unsigned int z = x ^ y;
    int n = 0;
    while (z) {
      n++;
      z = z & (z - 1);
    }
    return n;
  }
};
