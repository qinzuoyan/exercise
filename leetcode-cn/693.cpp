class Solution {
public:
    bool hasAlternatingBits(int n) {
        int i;
        do {
            i = n & 1;
            n = n >> 1;
        }
        while (n && ((n & 1) ^ i));
        return !n;
    }
};
