#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> fraction(vector<int> &cont) {
    int z = cont.size();
    int n = cont[z - 1], m = 1;
    for (int i = z - 2; i >= 0; i--) {
      int tn = n;
      n = cont[i] * n + m;
      m = tn;
    }
    vector<int> v(2);
    v[0] = n;
    v[1] = m;
    return v;
  }
};
