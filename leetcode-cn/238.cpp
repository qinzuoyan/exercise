#include <vector>
using namespace std;

class Solution {
public:
    // O(n)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> r(n);
        int left[n], right[n], s;
        s = 1;
        for (int i = 0; i < n - 1; i++) {
            s *= nums[i];
            left[i] = s;
        }
        s = 1;
        for (int i = n - 1; i > 0; i--) {
            s *= nums[i];
            right[i] = s;
        }
        for (int i = 0; i < n; i++) {
            s = 1;
            if (i > 0) s *= left[i - 1];
            if (i < n - 1) s *= right[i + 1];
            r[i] = s;
        }
        return r;
    }
};
