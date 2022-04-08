#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> r(numRows);
    r[0] = {1};
    for (int i = 1; i < numRows; i++) {
      vector<int>& v = r[i];
      v = r[i - 1];
      v.push_back(1);
      for (int j = v.size() - 2; j > 0; j--) {
        v[j] += v[j - 1];
      }
    }
    return r;
  }
};
