#include <vector>
using namespace std;

class Solution {
public:
    // O(n)
    int trap(vector<int>& height) {
        int max_pos = 0, n = height.size();
        for (int i = 1; i < n; i++) {
            if (height[i] > height[max_pos])
                max_pos = i;
        }
        int sum = 0;
        if (max_pos > 1) {
            int last_pos = 0, i = 1, s = 0;
            while (i <= max_pos) {
                if (height[i] >= height[last_pos]) {
                    sum += height[last_pos] * (i - last_pos - 1) - s;
                    last_pos = i;
                    s = 0;
                }
                else {
                    s += height[i];
                }
                i++;
            }
        }
        if (max_pos < n - 2) {
            int last_pos = n - 1, i = n - 2, s = 0;
            while (i >= max_pos) {
                if (height[i] >= height[last_pos]) {
                    sum += height[last_pos] * (last_pos - i - 1) - s;
                    last_pos = i;
                    s = 0;
                }
                else {
                    s += height[i];
                }
                i--;
            }
        }
        return sum;
    }
};
