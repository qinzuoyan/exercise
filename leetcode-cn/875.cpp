#include <vector>
#include <algorithm>
using namespace std;

class Solution {
 public:
  int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size(), max = 0;
    long long sum = 0;
    for (int i : piles) {
      sum += i;
      if (i > max) max = i;
    }
    if (sum <= h) return 1;
    int i = std::max(2, (int)(sum / h)), j = max;
    while (i < j) {
      int k = 0, m = (i + j) / 2;
      for (int i : piles) k += (i + m - 1) / m;
      if (k <= h)
        j = m;
      else
        i = m + 1;
    }
    return i;
  }
};
