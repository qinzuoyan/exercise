#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        sort(words.begin(), words.end());
        int max = 0, pre = -1, ret = -1;
        for (size_t i = 0; i < words.size(); i++) {
            string& w = words[i];
            int n = w.size();
            if (n == 1 || (pre != -1 && strncmp(w.data(), words[pre].data(), n-1) == 0)) {
                if (n > max) {
                    max = n;
                    ret = i;
                }
                pre = i;
            }
        }
        return ret == -1 ? "" : words[ret];
    }
};
