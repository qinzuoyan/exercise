#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int k = nums[i];
            if (k <= 0 || k > n) {
                nums[i] = 0;
            }
            else if (k < i + 1) {
                nums[k - 1] = k;
                nums[i] = 0;
            }
            else if (k > i + 1) {
                if (nums[k - 1] != k) {
                    nums[i] = nums[k - 1];
                    nums[k - 1] = k;
                    i--;
                }
                else {
                    nums[i] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                return i + 1;
        }
        return n + 1;
    }
};
