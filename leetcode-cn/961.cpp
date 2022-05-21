#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
  int repeatedNTimes(vector<int> &nums) {
    int a[10001];
    memset(a, 0, sizeof(a));
    for (int i : nums) {
      if (a[i] != 0)
        return i;
      ++a[i];
    }
    return 0;
  }
};
