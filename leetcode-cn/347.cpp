#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    typedef pair<int, int> pair_int;
    // O(nlog(k))
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; // num -> count
        priority_queue<pair_int, vector<pair_int>, greater<pair_int>> q; // count -> num
        vector<int> v;
        for (int n : nums) {
            m[n]++;
        }
        for (const auto& p : m) {
            if ((int)q.size() < k) {
                q.emplace(p.second, p.first);
            }
            else if (p.second > q.top().first) {
                q.pop();
                q.emplace(p.second, p.first);
            }
        }
        while (!q.empty()) {
            v.push_back(q.top().second);
            q.pop();
        }
        return v;
    }
};
