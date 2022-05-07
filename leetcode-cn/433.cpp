#include <climits>
#include <vector>
#include <string>
using namespace std;

class Solution {
 public:
  static const int LEN = 8;
  bool isChangeable(const string& x, const string& y) {
    int d = 0;
    for (int i = 0; i < LEN && d <= 1; ++i)
      if (x[i] != y[i]) ++d;
    return d <= 1;
  }
  int minMutation(string start, string end, vector<string>& bank) {
    int start_pos = -1, end_pos = -1, n = bank.size();
    for (int i = 0; i < n && (start_pos == -1 || end_pos == -1); ++i) {
      if (bank[i] == start)
        start_pos = i;
      else if (bank[i] == end)
        end_pos = i;
    }
    if (end_pos == -1) return -1;
    if (start_pos == -1) {
      start_pos = bank.size();
      bank.push_back(start);
      ++n;
    }
    vector<vector<int>> v(n);
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (isChangeable(bank[i], bank[j])) {
          v[i].push_back(j);
          v[j].push_back(i);
        }
      }
    }
    vector<bool> visited(n);
    vector<int> path(n, INT_MAX);
    path[start_pos] = 0;
    while (true) {
      int min_pos = -1, min_path = INT_MAX;
      for (int i = 0; i < n; ++i) {
        if (!visited[i] && path[i] < min_path) {
          min_path = path[i];
          min_pos = i;
        }
      }
      if (min_pos == end_pos || min_pos == -1) break;
      for (int k : v[min_pos]) {
        if (!visited[k] && min_path + 1 < path[k]) {
          path[k] = min_path + 1;
        }
      }
      visited[min_pos] = true;
    }
    return path[end_pos] == INT_MAX ? -1 : path[end_pos];
  }
};
