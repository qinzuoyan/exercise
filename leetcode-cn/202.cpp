#include <set>
using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        set<int> s({n});
        int k, sum, m;
        while (n != 1) {
            k = n, sum = 0;
            while (k) {
                m = k % 10;
                sum += m * m;
                k /= 10;
            }
            auto ret = s.insert(sum);
            if (!ret.second) {
                return false;
            }
            n = sum;
        }
        return true;
    }
};
