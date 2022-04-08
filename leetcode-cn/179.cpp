#include <algorithm>
#include <string>
#include <vector>
using namespace std;

bool comp(const string& a, const string& b) {
  const char* x = a.data();
  const char* y = b.data();
  while (*x || *y) {
    if (!*x) {
      x = a.data();
    }
    if (!*y) {
      y = b.data();
    }
    while (*x && *y && *x == *y) {
      x++;
      y++;
    }
    if (*x && *y) {
      return *x > *y;
    }
  }
  return a.data() < b.data();
}

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> v;
    char buf[20];
    for (int n : nums) {
      sprintf(buf, "%d", n);
      v.emplace_back(buf);
      // cout << buf << " " << v.back() << endl;
    }
    sort(v.begin(), v.end(), comp);
    if (v[0] == "0") {
      return "0";
    }
    string r;
    for (string s : v) {
      r += s;
    }
    return r;
  }
};
