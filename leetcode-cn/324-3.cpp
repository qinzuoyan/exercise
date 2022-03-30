#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // time: O(n)
    // space: O(m)
    const static int M = 5001;
    void wiggleSort(vector<int>& nums) {
        int a[M], n = nums.size();
        memset(a, 0, sizeof(a));
        for (int i : nums) {
            a[i]++;
        }
        int k = (n + 1) / 2, x = 0;
        for (int i = 0; i < M; i++) {
            while (a[i]--) {
                // nums[y] <= sorted_nums[x]
                int y = (n & 1 ?
                        (x / k) + (x % k) * 2 :
                        n - 2 + (x / k) - (x % k) * 2);
                nums[y] = i;
                x++;
            }
        }
    }
};
