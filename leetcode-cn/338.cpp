#include <vector>

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> r(n+1);
        for (int i = 1; i <= n; i++) {
            r[i] = r[i & (i - 1)] + 1;
        }
        return r;
    }
};
