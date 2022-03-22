#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int m = INT_MIN, d = 0, l = 0, r = 0, n = 0;
        for (int i : nums) {
            if (i == 0) {
                m = max(0, m);
                if (d != 0) {
                    if (n == 1 || d > 0) {
                        m = max(m, d);
                    }
                    else { // n > 1 && d < 0
                        m = max(m, d / l);
                        if (r > 0)
                            m = max(m, r);
                    }
                    d = 0;
                    l = 0;
                    r = 0;
                    n = 0;
                }
                continue;
            }
            if (i < 0)
                r = d;
            d = (d == 0 ? i : d * i);
            if (i < 0 && l == 0)
                l = d;
            n++;
        }
        if (d != 0) {
            if (n == 1 || d > 0) {
                m = max(m, d);
            }
            else {
                m = max(m, d / l);
                if (r > 0)
                    m = max(m, r);
            }
        }
        return m;
    }
};

