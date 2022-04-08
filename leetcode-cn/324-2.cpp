#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

class Solution {
 public:
  // time: O(nlog(n))
  // space: O(1)
  const static int M = 5001;
  void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int k = (n + 1) / 2, c = n, i = 0;
    while (c) {
      if (nums[i] >= M) {
        i++;
      } else {
        int t = nums[i], x = i;
        while (c) {
          // nums[x] <= nums[y]
          int y =
              (n & 1 ? (x % 2) * k + (x / 2) : (x % 2) * k + k - 1 - (x / 2));
          if (y == i) {
            nums[x] = t + M;
            c--;
            i++;
            break;
          }
          assert(nums[y] < M);
          nums[x] = nums[y] + M;
          c--;
          x = y;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      nums[i] -= M;
    }
  }
};
