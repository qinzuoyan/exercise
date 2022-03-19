#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    // O(n)
    int singleNumber(vector<int>& nums) {
        unordered_set<int> s;
        for (int i : nums) {
            auto it = s.find(i);
            if (it != s.end())
                s.erase(it);
            else
                s.insert(i);
        }
        return *s.begin();
    }
};
