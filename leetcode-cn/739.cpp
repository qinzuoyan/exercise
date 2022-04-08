#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  // O(m*n)
  vector<int> dailyTemperatures(vector<int>& temperatures) {
    int a[101], n = temperatures.size();
    memset(a, -1, sizeof(a));
    vector<int> r(n);
    for (int i = n - 1; i >= 0; i--) {
      int t = temperatures[i];
      if (a[t] != -1) r[t] = a[t] - i;
      for (int j = 30; j < t; j++) {
        a[j] = i;
      }
    }
    return r;
  }
};
