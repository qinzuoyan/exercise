#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    // O(2n)
    void sortColors(vector<int>& nums) {
        int c[3];
        memset(c, 0, sizeof(c));
        for (int i : nums)
            c[i]++;
        int k = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < c[i]; j++) {
                nums[k++] = i;
            }
        }
    }
};
