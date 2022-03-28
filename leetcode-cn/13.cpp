#include <string>
#include <cassert>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        char p = '\0';
        int r = 0;
        for (char c : s) {
            switch (c) {
                case 'I': 
                    {
                        r += 1;
                        break;
                    }
                case 'V': 
                    {
                        r += (p == 'I' ? 3 : 5);
                        break;
                    }
                case 'X': 
                    {
                        r += (p == 'I' ? 8 : 10);
                        break;
                    }
                case 'L': 
                    {
                        r += (p == 'X' ? 30 : 50);
                        break;
                    }
                case 'C': 
                    {
                        r += (p == 'X' ? 80 : 100);
                        break;
                    }
                case 'D': 
                    {
                        r += (p == 'C' ? 300 : 500);
                        break;
                    }
                case 'M': 
                    {
                        r += (p == 'C' ? 800 : 1000);
                        break;
                    }
                default:
                    assert(false);
            }
            p = c;
        }
        return r;
    }
};
