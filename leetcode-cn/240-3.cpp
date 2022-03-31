#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for (auto& v : matrix) {
            int i = 0, j = n - 1;
            if (target < v[i] || target > v[j]) {
                continue;
            }
            while (i < j) {
                int mid = (i + j) >> 1;
                int d = target - v[mid];
                if (d == 0) {
                    return true;
                }
                else if (d > 0) {
                    i = mid + 1;
                }
                else {
                    j = mid - 1;
                }
            }
            if (i == j && v[i] == target) {
                return true;
            } 
        }
        return false;
    }
};
