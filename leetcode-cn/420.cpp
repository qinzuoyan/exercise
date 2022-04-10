#include <string>
using namespace std;

class Solution {
  struct Del {
    int pos;
    int len;
    int edit;
    Del(int p, int l, int e) : pos(p), len(l), edit(e) {}
  };
public:
  int strongPasswordChecker(string password) {
    cout << password << endl;
    int n = password.size();
    int k = 0, i = 1;
    vector<int> v;
    vector<Del> v;
    for (; i < n; i++) {
      if (password[i] != password[i-1]) {
        if (i - k >= 3) {
          v.emplace_back(k, i - k, (i - k - 2) % 3);
          if (v.back().edit == 0) {
            v.back().edit = 3;
          }
        }
        k = i;
      }
    }
    if (i - k >= 3) {
      v.emplace_back(k, i - k, (i - k - 2) % 3);
      if (v.back().edit == 0) {
        v.back().edit = 3;
      }
    }
    if (
    for (int i : v) {
      cout << i << "," << endl;
    }
    return 0;
  }
};
