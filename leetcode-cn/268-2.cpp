#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    // time: O(n)
    // space: O(1)
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(-1);
        int *a = &nums[0], c = n, i = 0;
        while (c) {
            if (a[i] < 0) {
                i++;
            }
            else if (a[i] == i) {
                a[i] = -2;
                c--;
                i++;
            }
            else { // a[i] >= 0 && a[i] != i
                int j = a[i];
                a[i] = -1;
                while (j >= 0) {
                    int t = a[j];
                    a[j] = -2;
                    c--;
                    j = t;
                }
            }
        }
        for (i = 0; i <= n; i++) {
            if (a[i] == -1)
                return i;
        }
        return 0;
    }
};
