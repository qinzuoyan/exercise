#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    unordered_map<int, int> m;
    for (int i : nums) ++m[i];
    int r = 0;
    for (auto &i : m) {
      if (k == 0 && i.second > 1) ++r;
      else if (k > 0 && m.count(i.first + k) == 1) ++r;
    }
    return r;
  }
};
