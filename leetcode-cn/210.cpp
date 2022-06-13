#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<int> r;
    int a[numCourses], n = 0;  // in-degree
    memset(a, 0, sizeof(int) * numCourses);
    vector<int> b[numCourses];  // out-list
    for (vector<int> &v : prerequisites) {
      b[v[1]].push_back(v[0]);
      if (++a[v[0]] == 1) n++;
    }
    bool changed = true;
    while (changed) {
      changed = false;
      for (int i = 0; i < numCourses; i++) {
        if (a[i] == 0) {
          r.push_back(i);
          a[i] = -1;
          if (!b[i].empty()) {
            for (int j : b[i]) {
              if (--a[j] == 0) n--;
            }
            b[i].clear();
            changed = true;
          }
        }
      }
    }
    return n == 0 ? r : vector<int>();
  }
};
