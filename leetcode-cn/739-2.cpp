#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> r(n);
        stack<pair<int,int>> s;
        for (int i = 0; i < n; i++) {
            int t = temperatures[i];
            while (!s.empty() && s.top().first < t) {
                r[s.top().second] = i - s.top().second;
                s.pop();
            }
            s.emplace(t, i);
        }
        return r;
    }
};
