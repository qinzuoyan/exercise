#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int a[n + 1];
    memset(a, 0, sizeof(int) * (n + 1));
    for (int i : nums) {
      a[i]++;
    }
    for (int i = 0; i <= n; i++) {
      if (!a[i]) return i;
    }
    return 0;
  }
};
