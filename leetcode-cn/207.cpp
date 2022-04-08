#include <cstring>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int a[numCourses], n = 0;
    memset(a, 0, sizeof(int) * numCourses);
    vector<int> b[numCourses];
    for (vector<int>& v : prerequisites) {
      b[v[1]].push_back(v[0]);
      if (++a[v[0]] == 1) n++;
    }
    bool changed = true;
    while (n > 0 && changed) {
      changed = false;
      for (int i = 0; i < numCourses; i++) {
        if (n > 0 && a[i] == 0 && !b[i].empty()) {
          for (int j : b[i]) {
            if (--a[j] == 0) n--;
          }
          b[i].clear();
          changed = true;
        }
      }
    }
    return n == 0;
  }
};
