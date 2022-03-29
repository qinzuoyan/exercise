#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> r = digits;
        int k = 1;
        for (int i = r.size() - 1; i >= 0 && k; i--) {
            if (r[i] == 9) {
                r[i] = 0;
            }
            else {
                r[i]++;
                k = 0;
            }
        }
        if (k) {
            r.insert(r.begin(), 1);
        }
        return r;
    }
};
