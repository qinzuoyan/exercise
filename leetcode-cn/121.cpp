#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int m = prices[0], max = 0;
        for (int i : prices) {
            int k = i - m;
            if (k < 0)
                m = i;
            else if (k > max)
                max = k;
        }
        return max;
    }
};
