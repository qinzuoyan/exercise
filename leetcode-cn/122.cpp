#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int a[n][3];
        memset(a, 0, sizeof(n * 3));
        a[0][0] = 0;
        a[0][1] = -prices[0];
        a[0][2] = prices[0];
        for (int i = 1; i < n; i++) {
            a[i][0] = max(a[i-1][0], a[i-1][1] + prices[i]);
            if (prices[i] < a[i-1][2]) {
                // hold old -> hold new
                a[i][1] = a[i-1][1] + a[i-1][2] - prices[i];
                a[i][2] = prices[i];
            }
            else {
                // hold old -> hold old
                a[i][1] = a[i-1][1];
                a[i][2] = a[i-1][2];
            }
            if (a[i][1] < a[i-1][0] - prices[i]) {
                // no hold -> hold new
                a[i][1] = a[i-1][0] - prices[i];
                a[i][2] = prices[i];
            }
        }
        return max(a[n-1][0], a[n-1][1]);
    }
};
