#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> r;
        int i = 0, k;
        while (i < (int)nums.size()) {
            k = nums[i];
            if (k <= 0) {
                i++;
                continue;
            }
            if (k > i + 1) {
                if (nums[k - 1] > 0) {
                    nums[i] = nums[k - 1];
                    nums[k - 1] = -1;
                }
                else { // nums[k] < 0
                    nums[k - 1]--;
                    nums[i++] = 0;
                }
            }
            else if (k == i + 1) {
                nums[i++] = -1;
            }
            else { // k < i + 1
                nums[k - 1]--;
                nums[i++] = 0;
            }
        }
        for (i = 0; i < (int)nums.size(); i++) {
            if (nums[i] == 0) {
                r.push_back(i + 1);
            }
        }
        return r;
    }
};
