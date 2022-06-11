#include <vector>
using namespace std;

class Solution {
 public:
  int maximumCandies(vector<int> &candies, long long k) {
    long long sum = 0;
    for (int i : candies) sum += i;
    if (sum < k) return 0;
    int x = 1, y = sum / k;
    while (x < y) {
      int t = (x + y) / 2 + 1;
      long long m = 0;
      for (int i : candies) {
        m += i / t;
        if (m >= k) break;
      }
      if (m >= k)
        x = t;
      else
        y = t - 1;
    }
    return x;
  }
};
