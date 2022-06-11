#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> r;
    vector<string> v;
    partition(r, v, s.data());
    return r;
  }

  void partition(vector<vector<string>> &r, vector<string> &v, const char *p) {
    if (!*p) {
      r.push_back(v);
    }
    const char *q = p;
    while (*q) {
      const char *i = p, *j = q;
      while (i < j && *i == *j) {
        i++;
        j--;
      }
      q++;
      if (i >= j) {
        v.emplace_back(p, q - p);
        partition(r, v, q);
        v.pop_back();
      }
    }
  }
};
