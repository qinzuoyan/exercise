#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <unordered_map>
using namespace std;

class Solution {
 private:
  unordered_map<int, int> m;
  int k;

 public:
  Solution(int n, vector<int>& blacklist) {
    k = n - blacklist.size();
    if (blacklist.size()) {
      vector<int> a, b;
      for (int i : blacklist) {
        if (i < k)
          a.push_back(i);
        else
          b.push_back(i);
      }
      if (a.size()) {
        int j = 0, z = b.size(), p = k;
        if (z > 0) sort(b.begin(), b.end());
        for (int i : a) {
          while (j < z && b[j] == p) ++p, ++j;
          m[i] = p++;
        }
      }
    }
    srand(time(nullptr));
  }

  int pick() {
    int r = rand() % k;
    if (m.size()) {
      auto it = m.find(r);
      if (it != m.end()) return it->second;
    }
    return r;
  }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
