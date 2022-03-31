#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> r;
        for (int i = left; i <= right; i++) {
            int j = i;
            while (j) {
                int k = j % 10;
                if (!k || i % k != 0) {
                    break;
                }
                j /= 10;
            }
            if (!j) {
                r.push_back(i);
            }
        }
        return r;
    }
};
