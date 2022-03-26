#include <vector>
#include <string>
#include <stack>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for (auto& str : ops) {
            int c = 0;
            if (str == "+") {
                int p1 = s.top();
                s.pop();
                int p2 = s.top();
                s.push(p1);
                s.push(p1 + p2);
            }
            else if (str == "D") {
                s.push(s.top() * 2);
            }
            else if (str == "C") {
                s.pop();
            }
            else {
                s.push(atoi(str.c_str()));
            }
        }
        int r = 0;
        while (!s.empty()) {
            r += s.top();
            s.pop();
        }
        return r;
    }
};
