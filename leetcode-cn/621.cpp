#include <vector>
#include <queue>
#include <cstdint>
#include <cstring>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int a[26];
        memset(a, 0, sizeof(a));
        for (char c : tasks)
            a[c-'A']++;
        priority_queue<pair<int,int>> q; // <-pos, count>
        for (int i = 0; i < 26; i++) {
            if (a[i]) {
                q.emplace(-1, a[i]);
            }
        }
        int pos = -1;
        while (!q.empty()) {
            pair<int,int> p = q.top();
            if (p.first >= pos) {
                q.pop();
                if (--p.second != 0) {
                    p.first -= n + 1;
                    q.emplace(move(p));
                }
            }
            pos--;
        }
        return -pos - 1;
    }
};
