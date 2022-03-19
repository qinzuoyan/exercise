#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // O(n)
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> s(nums.begin(), nums.end());
        int max = 1;
        for (int i : s) {
            if (s.find(i-1) != s.end()) continue;
            int j = i + 1;
            while (s.find(j) != s.end()) j++;
            if (j - i > max) max = j - i;
        }
        return max;
    }
};
