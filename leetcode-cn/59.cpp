#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    // refer to problem 54
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int x = 0, y = 0, x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;
        int i = 0, d = 0, s = n * n;
        while (i < s) {
            matrix[y][x] = ++i;
            switch (d) {
                case 0: // to right
                    {
                        if (x != x2) {
                            x++;
                        }
                        else {
                            y++;
                            y1++;
                            d = 1;
                        }
                        break;
                    }
                case 1: // down
                    {
                        if (y != y2) {
                            y++;
                        }
                        else {
                            x--;
                            x2--;
                            d = 2;
                        }
                        break;
                    }
                case 2: // to left
                    {
                        if (x != x1) {
                            x--;
                        }
                        else {
                            y--;
                            y2--;
                            d = 3;
                        }
                        break;
                    }
                case 3: // up
                    {
                        if (y != y1) {
                            y--;
                        }
                        else {
                            x++;
                            x1++;
                            d = 0;
                        }
                        break;
                    }
                default:
                    assert(false);
            }
        }
        return matrix;
    }
};
