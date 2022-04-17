#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int minimumRounds(vector<int> &tasks) {
    unordered_map<int, int> m;
    for (int i : tasks) m[i]++;
    int r = 0;
    for (auto pr : m) {
      if (pr.second == 1) return -1;
      switch (pr.second % 6) {
        case 1:
        case 2:
        case 3:
          r += 1;
          break;
        case 4:
        case 5:
          r += 2;
          break;
      }
      r += pr.second / 6 * 2;
    }
    return r;
  }
};
