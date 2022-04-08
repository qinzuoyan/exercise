#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> r;
    vector<string> v;
    vector<int> a(s.size());  // 0:not processed, 1:true, -1:false
    partition(r, v, a, s.data(), s.data());
    return r;
  }

  bool partition(vector<vector<string>>& r, vector<string>& v, vector<int>& a,
                 const char* s, const char* p) {
    if (!*p) {
      r.push_back(v);
      return true;
    }
    if (a[p - s] == -1) {
      return false;
    }
    const char* q = p;
    while (*q) {
      const char *i = p, *j = q;
      while (i < j && *i == *j) {
        i++;
        j--;
      }
      q++;
      if (i >= j) {
        v.emplace_back(p, q - p);
        if (partition(r, v, a, s, q)) {
          a[p - s] = 1;
        }
        v.pop_back();
      }
    }
    if (a[p - s] == 0) {
      a[p - s] == -1;
    }
    return a[p - s] == 1;
  }
};
