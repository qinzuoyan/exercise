#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int v[amount + 1];
        v[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int k = -1;
            for (int j : coins) {
                if (i-j >= 0 && v[i-j] != -1 &&
                        (k == -1 || v[i-j] + 1 < k)) {
                    k = v[i-j] + 1;
                }
            }
            v[i] = k;
        }
        return v[amount];
    }
};
