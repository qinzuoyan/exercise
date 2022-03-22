#include <string>
#include <cstring>
#include <climits>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if (n1 == 0 || n2 == 0)
            return max(n1, n2);
        int a[n1 * n2];
        memset(a, -1, sizeof(int) * n1 * n2);
        return minDistance(a, n2, word1, n1 - 1, word2, n2 - 1);
    }

    int minDistance(int* a, int n, string& w1, int i1, string& w2, int i2) {
        if (i1 < 0) return i2 + 1;
        if (i2 < 0) return i1 + 1;
        int p = i1 * n + i2;
        if (a[p] >= 0)
            return a[p];
        int d = INT_MAX;
        if (i1 >= 0)
            d = min(d, minDistance(a, n, w1, i1-1, w2, i2) + 1);
        if (i2 >= 0)
            d = min(d, minDistance(a, n, w1, i1, w2, i2-1) + 1);
        if (i1 >= 0 && i2 >= 0) {
            int k = (w1[i1] == w2[i2] ? 0 : 1);
            d = min(d, minDistance(a, n, w1, i1-1, w2, i2-1) + k);
        }
        a[p] = d;
        return a[p];
    }
};
