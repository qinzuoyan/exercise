#include <vector>
using namespace std;

class Solution {
 public:
  pair<int, int> fraction(const vector<int> &cont, size_t i) {
    if (i == cont.size() - 1) {
      return pair<int, int>(cont[i], 1);
    } else {
      pair<int, int> r = fraction(cont, i + 1);
      return pair<int, int>(cont[i] * r.first + r.second, r.first);
    }
  }
  vector<int> fraction(vector<int> &cont) {
    pair<int, int> r = fraction(cont, 0);
    vector<int> v(2);
    v[0] = r.first;
    v[1] = r.second;
    return v;
  }
};
