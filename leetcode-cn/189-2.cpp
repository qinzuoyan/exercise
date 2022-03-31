#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        if (k == 0) {
            return;
        }
        auto it = nums.begin();
        advance(it, n - k);
        vector<int> t(it, nums.end());
        nums.resize(n - k);
        nums.insert(nums.begin(), t.begin(), t.end());
    }
};

