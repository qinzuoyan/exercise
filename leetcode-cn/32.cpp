#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int r = 0, n = 0;
        for (char c : s) {
            if (c == ')' && !st.empty() && st.top() == '(') {
                n += 2;
                st.pop();
                while (!st.empty() && st.top() < 0) {
                    n += -st.top();
                    st.pop();
                }
                if (n > r) r = n;
            }
            else {
                if (n > 0) {
                    st.push(-n);
                    n = 0;
                }
                st.push(c);
            }
        }
        return r;
    }
};
