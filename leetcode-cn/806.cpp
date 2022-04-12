#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string s) {
    int l = 1, n = 100, w = 0;
    for (char c : s) {
      int k = widths[c - 'a'];
      if (n < k) {
        l++;
        n = 100;
        w = 0;
      }
      n -= k;
      w += k;
    }
    vector<int> r = {l, w};
    return r;
  }
};
