#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxConsecutive(int bottom, int top, vector<int> &special) {
    sort(special.begin(), special.end());
    int max = special[0] - bottom, n = special.size();
    for (int i = 1; i < n; ++i) {
      if (special[i] - special[i - 1] - 1 > max)
        max = special[i] - special[i - 1] - 1;
    }
    if (top - special[n - 1] > max) max = top - special[n - 1];
    return max;
  }
};
