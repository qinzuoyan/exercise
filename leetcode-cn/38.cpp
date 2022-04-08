#include <cstdio>
#include <string>
using namespace std;

class Solution {
 public:
  string countAndSay(int n) {
    string pre = "1", cur;
    int i = 2;
    char buf[100];
    while (i <= n) {
      cur.clear();
      string cur;
      int m = pre.size();
      int c = 1;
      for (int j = 1; j < m; j++) {
        if (pre[j] != pre[j - 1]) {
          sprintf(buf, "%d", c);
          cur += buf;
          cur += pre[j - 1];
          c = 1;
        } else {
          c++;
        }
      }
      sprintf(buf, "%d", c);
      cur += buf;
      cur += pre[m - 1];
      pre.swap(cur);
      i++;
    }
    return pre;
  }
};
