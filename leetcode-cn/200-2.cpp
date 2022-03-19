#include <vector>
using namespace std;

class Solution {
public:
    void travel(vector<vector<char>>& g, size_t i, size_t j) {
        g[i][j] = '0';
        if (i > 0 && g[i-1][j] == '1') travel(g, i-1, j);
        if (j > 0 && g[i][j-1] == '1') travel(g, i, j-1);
        if (i < g.size() - 1 && g[i+1][j] == '1') travel(g, i+1, j);
        if (j < g[0].size() - 1 && g[i][j+1] == '1') travel(g, i, j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = 0;
        size_t m = grid.size(), n = grid[0].size();
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    r++;
                    travel(grid, i, j);
                }
            }
        }
        return r;
    }
};
