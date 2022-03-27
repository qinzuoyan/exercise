#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target, int i, int j) {
        if (i == j) {
            return nums[i] == target ? i : -1;
        }
        int m = (i + j) >> 1;
        if (nums[i] < nums[j]) {
            return target <= nums[m] ?
                search(nums, target, i, m) :
                search(nums, target, m + 1, j);
        }
        else {
            if (nums[i] <= nums[m]) {
                return nums[i] <= target && target <= nums[m] ?
                    search(nums, target, i, m) :
                    search(nums, target, m + 1, j);
            }
            else {
                return nums[m + 1] <= target && target <= nums[j] ?
                    search(nums, target, m + 1, j) :
                    search(nums, target, i, m);
            }
        }
    }

    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }
};
