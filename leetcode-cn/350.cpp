#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int a[1001], b[1001];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    for (int i : nums1) {
      a[i]++;
    }
    for (int i : nums2) {
      b[i]++;
    }
    vector<int> r;
    for (int i = 0; i <= 1000; i++) {
      if (a[i] && b[i]) {
        r.insert(r.end(), min(a[i], b[i]), i);
      }
    }
    return r;
  }
};
