#include <vector>
using namespace std;

// Time out ...
class Solution {
 public:
  const static long long M = 1000000007;
  struct N {
    int parent;
    int members;    // subtree member count
    int coins;      // coins to all subtree
    int coins_sum;  // subtree coins sum
    N() : parent(0), members(1), coins(0), coins_sum(0) {}
  };
  vector<int> bonus(int n, vector<vector<int>> &leadership,
                    vector<vector<int>> &operations) {
    N a[n + 1];
    for (auto &v : leadership) {
      int parent = v[0], child = v[1];
      a[child].parent = parent;
      while (parent) {
        a[parent].members += a[child].members;
        parent = a[parent].parent;
      }
    }
    vector<int> r;
    for (auto &v : operations) {
      if (v[0] == 1) {  // give one
        int i = v[1], c = v[2];
        while (i) {
          a[i].coins_sum += c;
          i = a[i].parent;
        }
      } else if (v[0] == 2) {  // give all
        int i = v[1], c = v[2];
        int k = a[i].members * c;
        a[i].coins += c;
        while (i) {
          a[i].coins_sum += k;
          i = a[i].parent;
        }
      } else {  // query all
        int i = v[1];
        long long c = a[i].coins_sum, m = a[i].members;
        i = a[i].parent;
        while (i) {
          c += a[i].coins * m;
          i = a[i].parent;
        }
        r.push_back(c % M);
      }
    }
    return r;
  }
};
