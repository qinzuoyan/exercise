#include <vector>
using namespace std;

class Solution {
public:
    void findTargetSumWays(vector<int>& nums, size_t pos, int target, int current, int* count) {
        if (pos == nums.size()) {
            if (current == target)
                *count++;
            return;
        }
        findTargetSumWays(nums, pos+1, target, current + nums[pos], count);
        findTargetSumWays(nums, pos+1, target, current - nums[pos], count);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        findTargetSumWays(nums, 0, target, 0, &count);
        return count;
    }
};
