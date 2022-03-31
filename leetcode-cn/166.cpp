#include <string>
#include <map>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) {
            return "0";
        }
        string r;
        long long n = numerator, d = denominator;
        if ((n < 0 && d > 0) || (n > 0 && d < 0)) {
            r += "-";
        }
        if (n < 0) n = -n;
        if (d < 0) d = -d;
        long long t = n / d;
        char buf[100];
        sprintf(buf, "%lld", t);
        r += buf;
        long long m = n % d * 10;
        if (m == 0) {
            return r;
        }
        r.push_back('.');
        map<int, int> loop;
        while (m) {
            auto ret = loop.insert(pair<int,int>(m, r.size()));
            if (!ret.second) {
                r.insert(ret.first->second, 1, '(');
                r.push_back(')');
                break;
            }
            r.push_back('0' + m / d);
            m = m % d * 10;
        }
        return r;
    }
};
