#include <vector>
using namespace std;

class Solution {
 public:
  int maximumWealth(vector<vector<int>> &accounts) {
    int m = 0;
    for (auto &v : accounts) {
      int n = 0;
      for (int i : v) n += i;
      if (n > m) m = n;
    }
    return m;
  }
};
