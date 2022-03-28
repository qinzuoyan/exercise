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
        int n = s.size(), m = words.size(), z = words[0].size();
        if (n < m * z) {
            return r;
        }

        int c[m], nextid = 0;
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

        int b[z][nextid], match[z];
        memset(b, 0, sizeof(int) * z * nextid);
        memset(match, 0, sizeof(int) * z);
        for (int i = 0, j = i - m * z; i < na; i++, j++) {
            int k = i % z;
            if (j >= 0) {
                int id = a[j];
                if (id != -1) {
                    if (b[k][id] == c[id] + 1) {
                        match[k]++;
                    }
                    else if (b[k][id] == c[id]) {
                        match[k]--;
                    }
                    b[k][id]--;
                }
            }
            int id = a[i];
            if (id != -1) {
                if (b[k][id] == c[id] - 1) {
                    match[k]++;
                }
                else if (b[k][id] == c[id]) {
                    match[k]--;
                }
                b[k][id]++;
            }
            if (match[k] == nextid) {
                r.push_back(j + z);
            }
        }

        return r;
    }
};
