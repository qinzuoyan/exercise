#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int kthSmallest(vector<vector<int>> &matrix, int k) {
    int m = matrix.size(), n = matrix[0].size();
    priority_queue<int> q;
    for (auto &v : matrix) {
      for (int i : v) {
        if ((int)q.size() < k) {
          q.push(i);
        } else if (i < q.top()) {
          q.push(i);
          q.pop();
        }
      }
    }
    return q.top();
  }
};
