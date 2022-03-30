#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // time: O(nlog(n))
    // space: O(n)
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> v(nums);
        int k = (n + 1) / 2;
        if (n & 1) {
            int x = 0, i = 0, j = k;
            while (i < k) {
                nums[x++] = v[i++];
                if (j < n) {
                    nums[x++] = v[j++];
                }
            }
        }
        else {
            int x = 0, i = k - 1, j = n - 1;
            while (i >= 0) {
                nums[x] = v[i--];
                x = (x+1) % n;
                nums[x] = v[j--];
                x = (x+1) % n;
            }
        }
    }
};
