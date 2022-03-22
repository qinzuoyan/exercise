class Solution {
public:
    int numTrees(int n) {
        int a[n+1];
        a[0] = 1;
        a[1] = 1;
        for (int i = 2; i <= n; i++) {
            int s = 0;
            for (int l = 0; l <= i - 1; l++) {
                s += a[l] * a[i - l - 1];
            }
            a[i] = s;
        }
        return a[n];
    }
};
