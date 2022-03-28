#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> r;
        int n = s.size(), m = words.size(), z = words[0].size(), nextid= 0;
        if (n < m * z) {
            return r;
        }

        int c[m];
        memset(c, 0, sizeof(int) * m);
        unordered_map<string, int> stoi;
        for (auto& w : words) {
            auto it = stoi.find(w);
            if (it == stoi.end()) {
                c[nextid]++;
                stoi.emplace(w, nextid++);
            }
            else {
                c[it->second]++;
            }
        }

        int na = n - z + 1;
        int a[na];
        memset(a, -1, sizeof(int) * na);
        for (int i = 0; i < na; i++) {
            string str = s.substr(i, z);
            auto it = stoi.find(str);
            if (it != stoi.end()) {
                a[i] = it->second;
            }
        }

        int b[nextid];
        for (int i = 0; i < z; i++) {
            int x = i, y = i, match = 0;
            memset(b, 0, sizeof(int) * nextid);
            for (int j = 0; j < m && x < na; j++) {
                int id = a[x];
                if (id != -1) {
                    if (b[id] == c[id] - 1) {
                        match++;
                    }
                    else if (b[id] == c[id]) {
                        match--;
                    }
                    b[id]++;
                }
                x += z;
            }
            if (match == nextid) {
                r.push_back(y);
            }
            while (x < na) {
                int id = a[y];
                if (id != -1) {
                    if (b[id] == c[id] + 1) {
                        match++;
                    }
                    else if (b[id] == c[id]) {
                        match--;
                    }
                    b[id]--;
                }
                y += z;
                id = a[x];
                if (id != -1) {
                    if (b[id] == c[id] - 1) {
                        match++;
                    }
                    else if (b[id] == c[id]) {
                        match--;
                    }
                    b[id]++;
                }
                x += z;
                if (match == nextid) {
                    r.push_back(y);
                }
            }
        }

        if (z > 1 && !r.empty()) {
            sort(r.begin(), r.end());
        }

        return r;
    }
};
