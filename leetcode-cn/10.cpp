#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int sn = s.size(), pn = p.size();
        vector<vector<int>> v(sn + 1, vector<int>(pn + 1)); // 1 : true, 2 : false
        v[0][0] = 1;
        return isMatch(s, p, v, sn, pn);
    }

    bool isMatch(string& s, string& p, vector<vector<int>>& v, int sn, int pn) {
        if (v[sn][pn] > 0) {
            return v[sn][pn] == 1;
        }
        if (pn == 0) {
            v[sn][pn] = 2;
            return false;
        }
        if (sn == 0) {
            if (p[pn-1] == '*' && isMatch(s, p, v, sn, pn - 2)) {
                v[sn][pn] = 1;
                return true;
            }
            else {
                v[sn][pn] = 2;
                return false;
            }
        }
        if ((p[pn-1] == '.' || p[pn-1] == s[sn-1])
                && isMatch(s, p, v, sn - 1, pn - 1)) {
            v[sn][pn] = 1;
            return true;
        }
        else if (p[pn-1] == '*') {
            if (isMatch(s, p, v, sn, pn - 2)) {
                v[sn][pn] = 1;
                return true;
            }
            if ((p[pn-2] == '.' || p[pn-2] == s[sn-1])
                    && (isMatch(s, p, v, sn - 1, pn) || isMatch(s, p, v, sn - 1, pn - 2))) {
                v[sn][pn] = 1;
                return true;
            }
        }
        v[sn][pn] = 2;
        return false;
    }
};
