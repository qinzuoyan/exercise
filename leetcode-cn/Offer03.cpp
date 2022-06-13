#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int findRepeatNumber(vector<int> &nums) {
    unordered_set<int> m;
    for (int i : nums) {
      auto pr = m.insert(i);
      if (!pr.second) return i;
    }
    return 0;
  }
};
