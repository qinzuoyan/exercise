#include <vector>
using namespace std;

class Solution {
public:
 int largestCombination(vector<int>& candidates) {
   int a[24] = {0}, k = 0;
   for (int i : candidates) {
     k = 0;
     while (i) {
       if (i & 1) ++a[k];
       i >>= 1;
       ++k;
     }
   }
   int max = 0;
   for (int i = 0; i < 24; ++i) {
     if (a[i] > max) max = a[i];
   }
   return max;
 }
};
