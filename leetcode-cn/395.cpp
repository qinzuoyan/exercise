#include <string>
#include <cstring>
#include <queue>
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.size();
        if (k == 1) {
            return n;
        }
        if (k > n) {
            return 0;
        }
        int a[26];
        priority_queue<pair<int,int>> q;
        q.emplace(n, 0);
        while (q.size()) {
            auto pr = q.top();
            const char *i = s.data() + pr.second;
            const char *j = i + pr.first;
            q.pop();
            const char* x = i;
            memset(a, 0, sizeof(a));
            while (x < j) {
                a[*x - 'a']++;
                x++;
            }
            int c0 = 0, c1 = 0;
            for (int y = 0; y < 26; y++) {
                if (a[y]) {
                    if (a[y] < k) {
                        a[y] = -1;
                        c0++;
                    }
                    else {
                        c1++;
                    }
                }
            }
            if (c0 == 0) {
                return j - i;
            }
            if (c1 == 0) {
                continue;
            }
            x = i;
            while (x < j) {
                if (a[*x - 'a'] < 0) {
                    if (x - i >= k) {
                        q.emplace(x - i, i - s.data());
                    }
                    i = x + 1;
                }
                x++;
            }
            if (x - i >= k) {
                q.emplace(x - i, i - s.data());
            }
        }
        return 0;
    }
};
