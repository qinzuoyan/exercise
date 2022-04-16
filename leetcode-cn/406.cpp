#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

bool compare406(const vector<int>& a, const vector<int>& b) {
  if (a[0] > b[0])
    return true;
  else if (a[0] < b[0])
    return false;
  else
    return a[1] < b[1];
}

class Solution {
 public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    int n = people.size();
    sort(people.begin(), people.end(), compare406);
    int a[n];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
      vector<int>& v = people[i];
      int move = i - v[1];
      if (move > 0) {
        memmove(a + v[1] + 1, a + v[1], sizeof(int) * move);
      }
      a[v[1]] = i;
    }
    vector<vector<int>> r(n);
    for (int i = 0; i < n; i++) {
      r[i] = people[a[i]];
    }
    return r;
  }
};
