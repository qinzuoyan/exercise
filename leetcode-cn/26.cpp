#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int i = 1;
        while (i < n && nums[i] != nums[i-1]) {
            i++;
        }
        int j = i;
        while (i < n) {
            if (nums[i] != nums[i-1]) {
                nums[j++] = nums[i];
            }
            i++;
        }
        return j;
    }
};
