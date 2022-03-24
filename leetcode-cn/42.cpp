#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    // O(nlog(n))
    int trap(vector<int>& height) {
        int n = height.size();
        priority_queue<pair<int,int>> q;
        for (int i = 0; i < n; i++) {
            q.emplace(height[i], i);
        }
        int sum = 0;
        int l = q.top().second;
        int r = l;
        q.pop();
        while (!q.empty()) {
            int h = q.top().first;
            int p = q.top().second;
            if (p > r) {
                if (p == r + 1) {
                    ++r;
                }
                else {
                    int s = h * (p - r - 1);
                    ++r;
                    while (r < p) {
                        s -= height[r];
                        ++r;
                    }
                    sum += s;
                }
            }
            else if (p < l) {
                if (p + 1 == l) {
                    --l;
                }
                else {
                    int s = h * (l - p - 1);
                    --l;
                    while (l > p) {
                        s -= height[l];
                        --l;
                    }
                    sum += s;
                }
            }
            q.pop();
        }
        return sum;
    }
};
