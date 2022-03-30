#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int a[1001];
        memset(a, 0, sizeof(a));
        for (int i : nums1) {
            a[i]++;
        }
        for (int i : nums2) {
            a[i] += (1<<10);
        }
        vector<int> r;
        for (int i = 0; i <= 1000; i++) {
            if (a[i]) {
                int k1 = a[i] & ((1<<10)-1);
                int k2 = a[i] >> 10;
                if (k1 && k2) {
                    r.insert(r.end(), min(k1, k2), i);
                }
            }
        }
        return r;
    }
};
