#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int a[n], b[n];
        a[0] = nums[0];
        for (int i = 1; i < n; i++) {
            a[i] = nums[i] + b[i-1];
            b[i] = max(a[i-1], b[i-1]);
        }
        return max(a[n-1], b[n-1]);
    }
};
