#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> r;
        for (int num : nums) {
            num = num > 0 ? num - 1 : -num - 1;
            if (nums[num] > 0)
                nums[num] = -nums[num];
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (nums[i] > 0) {
                r.push_back(i + 1);
            }
        }
        return r;
    }
};
