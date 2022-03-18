#include <string>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> st;
        stack<string> ss;
        int k = 0;
        string t;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            }
            else if (c == '[') {
                st.push(k);
                ss.push(t);
                k = 0;
                t.clear();
            }
            else if (islower(c)) {
                t += c;
            }
            else { // c == ']'
                int n = st.top();
                string v = ss.top();
                st.pop();
                ss.pop();
                for (int i = 0; i < n; i++)
                    v.append(t);
                t = v;
            }
        }
        return t;
    }
};
