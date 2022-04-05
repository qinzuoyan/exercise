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
        int a[20] = {0, 0,1,1,0,1, 0,1,0,0,0, 1,0,1,0,0, 0,1,0,1};
        int last = bitCount(left);
        int s = a[last];
        for (int i = left + 1; i <= right; i++) {
            last = (i & 1) ? (last + 1) : bitCount(i);
            s += a[last];
        }
        return s;
    }
};
