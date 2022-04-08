#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int sum = mean * (n + rolls.size());
    for (int i : rolls) {
      sum -= i;
    }
    vector<int> r;
    if (sum < n || sum > n * 6) {
      return r;
    }
    while (sum > n) {
      int k = min(sum - n + 1, 6);
      r.push_back(k);
      sum -= k;
      n--;
    }
    if (sum > 0) {
      r.insert(r.end(), sum, 1);
    }
    return r;
  }
};
