#include <vector>
using namespace std;

class Solution {
 public:
  int minCount(vector<int> &coins) {
    int r = 0;
    for (int i : coins) {
      r += (i + 1) / 2;
    }
    return r;
  }
};
