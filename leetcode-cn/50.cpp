class Solution {
public:
    double myPow(double x, int n) {
        long long m = n;
        if (m < 0)
            m = -m;
        double r = 1.0, y = x;
        long k = 1;
        while (m) {
            if (m & k) {
                r *= y;
                m -= k;
            }
            k = k << 1;
            y = y * y;
        }
        return n > 0 ? r : 1 / r;
    }
};
