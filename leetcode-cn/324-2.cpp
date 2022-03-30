#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> v(nums);
        int k = (n + 1) / 2, t = nums[0], c = n - 1, i = 1;
        while (c) {
            int j = (n & 1 ?
                    (i % 2) * k + (i / 2) :
                    (i % 2) * k + k - 1 - (i / 2));
            if (nums[j] >= 0) {
                nums[i] = -nums[j];
                i = j;
                c--;
            }
            else {
                i = (i + 1) % n;
            }
        }
        nums[i] = t;
    }
};
