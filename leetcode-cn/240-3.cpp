#include <vector>
using namespace std;

class Solution {
 public:
  // O(mlog(n)) : 84ms
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n = matrix[0].size();
    int j = n - 1;
    for (auto& v : matrix) {
      int i = 0;
      if (target < v[i] || target > v[j]) {
        continue;
      }
      while (i <= j) {
        int mid = (i + j) >> 1;
        int d = target - v[mid];
        if (d == 0) {
          return true;
        } else if (d > 0) {
          i = mid + 1;
        } else {
          j = mid - 1;
        }
      }
    }
    return false;
  }
};
