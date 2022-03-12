#include <vector>
#include <utility>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<pair<int,int>>> vec1,vec2;
        vec1.resize(matrix.size());
        vec2.resize(matrix.size());
        int r = 0;
        for (size_t i = 0; i < matrix.size(); i++) {
            vector<char>& m = matrix[i];
            vector<pair<int,int>>& v1 = vec1[i];
            vector<pair<int,int>>& v2 = vec2[i];
            v1.resize(m.size());
            v2.resize(m.size());
            for (size_t j = 0; j < m.size(); j++) {
                if (m[j] == '0') {
                    v1[j] = make_pair(0,0);
                    v2[j] = make_pair(0,0);
                } else {
                    /*
                    pair<int,int> left1,up1;
                    if (j > 0) left1 = vec1[i][j-1];
                    if (i > 0) up1 = vec1[i-1][j];
                    v[j].first = min(left.first, up.first-1);
                    v[j].second = min(left.second-1, up.second);
                    int t = v[j].first * v[j].second;
                    if (t > r) r = t;
                    */
                }
            }
        }
    }
};
