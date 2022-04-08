#include <vector>
using namespace std;

class Solution {
 public:
  void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    k = k % n;
    if (k == 0) {
      return;
    }
    vector<int> t(n);
    int s = n - k;
    for (int i = 0; i < k; i++) {
      t[i] = nums[s + i];
    }
    for (int i = 0; i < s; i++) {
      t[k + i] = nums[i];
    }
    nums.swap(t);
  }
};
