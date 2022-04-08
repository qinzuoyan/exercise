#include <climits>
#include <cstring>
#include <string>
using namespace std;

class Solution {
 public:
  int firstUniqChar(string s) {
    int a[26], n = s.size();
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      int c = s[i] - 'a';
      if (a[c])
        a[c] = -(i + 1);
      else
        a[c] = i + 1;
    }
    int idx = INT_MAX;
    for (int i = 0; i < 26; i++) {
      if (a[i] > 0 && a[i] < idx) {
        idx = a[i];
      }
    }
    return idx == INT_MAX ? -1 : idx - 1;
  }
};
