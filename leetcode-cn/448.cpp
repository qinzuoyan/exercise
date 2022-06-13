#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = nums.size();
    int a[n + 1];
    memset(a, 0, sizeof(int) * (n + 1));
    for (int i : nums) {
      a[i]++;
    }
    vector<int> r;
    for (int i = 1; i <= n; i++) {
      if (a[i] == 0) {
        r.push_back(i);
      }
    }
    return r;
  }
};
