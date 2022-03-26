#include <vector>
using namespace std;

class Solution {
public:
    // O(n^2)
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int a[n + 2];
        a[n - 1] = a[n] = a[n + 1] = 0;
        for (int i = n - 2; i >= 0; --i) {
            int ai = prices[i];
            int max = a[i + 1];
            for (int j = i + 1; j < n; ++j) {
                int aj = prices[j];
                if (aj > ai && (a[j + 2] + aj - ai > max)) {
                    max = a[j + 2] + aj - ai;
                }
            }
            a[i] = max;
        }
        return a[0];
    }
};
