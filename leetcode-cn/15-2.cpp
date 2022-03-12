#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int a[3];
        vector<vector<int>> r;
        size_t n = nums.size();
        if (n < 3) return r;
        sort(nums.begin(), nums.end());
        if (nums[0] > 0 || nums[n-1] < 0) return r;
        for (size_t i = 0; i < n - 2 && nums[i] <= 0; i++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            size_t j = i + 1;
            size_t k = n - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < 0) {
                    j++;
                }
                else if (sum > 0) {
                    k--;
                }
                else {
                    a[0] = nums[i];
                    a[1] = nums[j];
                    a[2] = nums[k];
                    r.emplace_back(a, a+3);
                    while (j < k && nums[j] == nums[j+1]) j++;
                    while (j < k && nums[k-1] == nums[k]) k--;
                    j++;
                    k--;
                }
            }
        }
        return r;
    }
};
