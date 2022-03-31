#include <cstdint>

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t m = 0, x = 1 << 31;
        while (n) {
            if (n & 1) {
                m |= x;
            }
            n >>= 1;
            x >>= 1;
        }
        return m;
    }
};
