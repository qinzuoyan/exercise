#include <cstdint>
using namespace std;

class Solution {
 public:
  int getSum(int a, int b) {
    uint32_t a1 = (uint32_t)a;
    uint32_t b1 = (uint32_t)b;
    while (b1) {
      uint32_t c = (a1 & b1) << 1;
      a1 ^= b1;
      b1 = c;
    }
    return (int)a1;
  }
};
