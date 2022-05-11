#include <vector>
#include <string>
#include <map>
using namespace std;

class Solution {
 public:
  int countDistinct(vector<int>& nums, int k, int p) {
    int n = nums.size(), s = 0, c = 0, r = 0;
    map<pair<int, int>, vector<int>> m[201];
    for (int i = 0; i < n; ++i) {
      if (nums[i] % p == 0) ++c;
      if (c > k) {
        while (nums[s] % p != 0) ++s;
        ++s;
        --c;
      }
      for (int j = s; j <= i; ++j) {
        int len = i - j + 1, s1 = 0, s2 = 0, p = 1;
        for (int x = j; x <= i; ++x) {
          s1 += nums[x];
          s2 += p * nums[x];
          ++p;
        }
        auto& v = m[len][pair<int, int>(s1, s2)];
        bool exist = false;
        if (v.size()) {
          for (int x : v) {
            int y = 0;
            for (; y < len; ++y) {
              if (nums[j + y] != nums[x + y]) break;
            }
            if (y == len) {
              exist = true;
              break;
            }
          }
        }
        if (!exist) {
          v.push_back(j);
          ++r;
        } else {
          break;
        }
      }
    }
    return r;
  }
};
