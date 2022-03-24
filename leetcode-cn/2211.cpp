#include <string>
using namespace std;

class Solution {
public:
    int countCollisions(string directions) {
        int z = directions.size();
        int i = 0, j = z - 1, n = 0;
        while (i < z && directions[i] == 'L') i++;
        while (j >= 0 && directions[j] == 'R') j--;
        if (j - i <= 0)
            return 0;
        while (i <= j) {
            if (directions[i] == 'R') {
                if (directions[i+1] == 'L') {
                    n += 2;
                    i++;
                }
                else {
                    n += 1;
                }
            }
            else if (directions[i] == 'L') {
                n += 1;
            }
            i++;
        }
        return n;
    }
};
