#include <vector>
using namespace std;

class Solution {
 public:
  void duplicateZeros(vector<int>& arr) {
    int n = arr.size(), m = 0;
    for (int i : arr) {
      if (i == 0) ++m;
    }
    if (m > 0) {
      arr.resize(n + m);
      int i = n - 1, j = n + m - 1;
      while (i >= 0) {
        if (arr[i])
          arr[j--] = arr[i--];
        else {
          arr[j--] = 0;
          arr[j--] = 0;
          --i;
        }
      }
      arr.resize(n);
    }
  }
};
