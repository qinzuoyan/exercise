#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    // O(n)
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> r(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            int t = temperatures[i];
            while (!s.empty() && temperatures[s.top()] < t) {
                r[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return r;
    }
};
