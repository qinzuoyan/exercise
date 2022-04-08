#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (int i : nums) {
      if (!s.insert(i).second) return true;
    }
    return false;
  }
};
