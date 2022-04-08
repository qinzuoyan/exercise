#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> r;
    if (list1.empty() || list2.empty()) return r;
    unordered_map<string, size_t> m;
    for (size_t i = 0; i < list1.size(); i++) {
      m[list1[i]] = i;
    }
    size_t min_sum = 10000;
    for (size_t i = 0; i < list2.size(); i++) {
      unordered_map<string, size_t>::iterator it = m.find(list2[i]);
      if (it != m.end()) {
        size_t sum = i + it->second;
        if (sum == min_sum) {
          r.push_back(list2[i]);
        } else if (sum < min_sum) {
          r.clear();
          r.push_back(list2[i]);
          min_sum = sum;
        }
      }
    }
    return r;
  }
};
