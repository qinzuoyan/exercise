#include <vector>
using namespace std;

class Solution {
 public:
  void run(char *a, char *b, int m, int i, vector<int>& r) {
    if (i >= m)
      return;
    char end = '9';
    if (i == m - 1) {
      int c = strncmp(a, b, i);
      if (c > 0)
        return;
      if (c == 0)
        end = b[i];
    }
    char begin = (i == 0 ? '1' : '0');
    for (char c = begin; c <= end; c++) {
      a[i] = c;
      a[i+1] = '\0';
      r.push_back(atoi(a));
      run(a, b, m, i+1, r);
    }
  }
  vector<int> lexicalOrder(int n) {
    vector<int> r;
    char a[10];
    char b[10];
    int m = sprintf(b, "%d", n);
    run(a, b, m, 0, r);
    return r;
  }
};
