#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& visit, size_t i, size_t j,
            const string& word, size_t pos) {
        if (visit[i][j] || board[i][j] != word[pos])
            return false;
        visit[i][j] = true;
        if (pos == word.size() - 1)
            return true;
        if (i > 0 && exist(board, visit, i-1, j, word, pos+1))
            return true;
        if (i < board.size()-1 && exist(board, visit, i+1, j, word, pos+1))
            return true;
        if (j > 0 && exist(board, visit, i, j-1, word, pos+1))
            return true;
        if (j < board[0].size()-1 && exist(board, visit, i, j+1, word, pos+1))
            return true;
        visit[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        size_t m = board.size();
        size_t n = board[0].size();
        vector<vector<bool>> visit(m);;
        for (vector<bool>& v : visit)
            v.resize(n);
        for (size_t i = 0; i < m; i++)
            for (size_t j = 0; j < n; j++)
                if (exist(board, visit, i, j, word, 0))
                    return true;
        return false;
    }
};
