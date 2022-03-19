#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int b[n];
        b[0] = 0;
        b[1] = nums[0];
        for (int i = 2; i < n; i++)
            b[i] = max(b[i-1], nums[i-1]+b[i-2]);
        return max(b[n-1], nums[n-1]+b[n-2]);
    }
};
