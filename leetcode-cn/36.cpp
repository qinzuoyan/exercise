#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int a[10];
        for (int i = 0; i < 9; i++) {
            memset(a, 0, sizeof(a));
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    if (a[k])
                        return false;
                    a[k] = 1;
                }
            }
        }
        for (int j = 0; j < 9; j++) {
            memset(a, 0, sizeof(a));
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    int k = board[i][j] - '0';
                    if (a[k])
                        return false;
                    a[k] = 1;
                }
            }
        }
        for (int x = 0; x < 9; x += 3) {
            for (int y = 0; y < 9; y += 3) {
                memset(a, 0, sizeof(a));
                for (int i = x; i < x + 3; i++) {
                    for (int j = y; j < y + 3; j++) {
                        if (board[i][j] != '.') {
                            int k = board[i][j] - '0';
                            if (a[k])
                                return false;
                            a[k] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};
