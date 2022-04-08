#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return 0;
    /*
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<pair<int,int>>> v;
    v.resize(m);
    for(int i = 0; i < m; i++) {
        vector<pair<int,int>>& vm = matrix[i];
        vm.resize(n);
        for(int j = 0; j < n; j++) {
            if (matrix[i][j] == '1') {
                pair<int,int> left, up;
                if (j > 0) left = vm[j-1];
                if (i > 0) up = v[i-1][j];
                vm[j].first = max(left.first + 1, up.first);
                vm[j].second = max(left.second, up.second + 1);
            }
        }
    }
    return v[m-1][n-1];
    */
    return 0;
  }
};
