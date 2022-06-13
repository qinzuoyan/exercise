#include <algorithm>
#include <set>
#include <utility>
#include <vector>
using namespace std;

bool SortCompare(const vector<int> &a, const vector<int> &b) {
  if (a.size() < 3) return true;
  if (b.size() < 3) return false;
  if (a[0] < b[0]) return true;
  if (a[0] > b[0]) return false;
  if (a[1] < b[1]) return true;
  if (a[1] > b[1]) return false;
  return a[2] < b[2];
}

bool UniqueCompare(const vector<int> &a, const vector<int> &b) {
  return a[0] == b[0] && a[1] == b[1] && a[2] == b[2];
}

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> r;
    if (nums.size() < 3) return r;
    sort(nums.begin(), nums.end());
    vector<int> t;
    size_t n = 0;
    for (int i : nums) {
      if (i != 0 && n >= 2 && i == t[n - 1] && i == t[n - 2]) continue;
      if (i == 0 && n >= 3 && t[n - 1] == 0 && t[n - 2] == 0 && t[n - 3] == 0)
        continue;
      t.push_back(i);
      n++;
    }
    if (n < 3) return r;
    if (t[0] > 0 || t[n - 1] < 0) return r;
    for (size_t i = 0; i < n - 2 && t[i] <= 0; i++) {
      size_t k = n - 1;
      for (size_t j = i + 1; j < k; j++) {
        int sum = t[i] + t[j];
        while (j < k && sum + t[k] > 0) k--;
        if (j < k && sum + t[k] == 0) {
          vector<int> v;
          v.push_back(t[i]);
          v.push_back(t[j]);
          v.push_back(t[k]);
          r.emplace_back(std::move(v));
        }
      }
    }
    if (!r.empty()) {
      sort(r.begin(), r.end(), SortCompare);
      r.erase(unique(r.begin(), r.end(), UniqueCompare), r.end());
    }
    return r;
  }
  /*
  vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> r;
      if (nums.size() < 3) return r;
      sort(nums.begin(), nums.end());
      vector<int> t;
      size_t n = 0;
      for (int i : nums) {
          if (i != 0 && n >= 2 && i == t[n-1] && i == t[n-2])
              continue;
          if (i == 0 && n >= 3 && t[n-1] == 0 && t[n-2] == 0 && t[n-3] == 0)
              continue;
          t.push_back(i);
          n++;
      }
      if (n < 3) return r;
      set<vector<int>> s;
      if (t[0] > 0 || t[n-1] < 0) return r;
      for (size_t i = 0; i < n - 2 && t[i] <= 0; i++) {
          size_t k = n - 1;
          for (size_t j = i + 1; j < k; j++) {
              int sum = t[i] + t[j];
              while (j < k && sum + t[k] > 0) k--;
              if (j < k && sum + t[k] == 0) {
                  vector<int> v;
                  v.push_back(t[i]);
                  v.push_back(t[j]);
                  v.push_back(t[k]);
                  s.emplace(std::move(v));
              }
          }
      }
      if (!s.empty()) {
          for (const vector<int>& v : s) {
              r.push_back(v);
          }
      }
      return r;
  }
  */
  /*
  vector<vector<int>> threeSum(vector<int>& nums) {
      vector<vector<int>> r;
      size_t n = nums.size();
      if (n < 3) return r;
      sort(nums.begin(), nums.end());
      if (nums[0] > 0 || nums[n-1] < 0) return r;
      for (size_t i = 0; i < n - 2 && nums[i] <= 0; i++) {
          size_t k = n - 1;
          for (size_t j = i + 1; j < k; j++) {
              int sum = nums[i] + nums[j];
              while (j < k && sum + nums[k] > 0) k--;
              if (j < k && sum + nums[k] == 0) {
                  vector<int> v;
                  v.push_back(nums[i]);
                  v.push_back(nums[j]);
                  v.push_back(nums[k]);
                  r.emplace_back(std::move(v));
              }
          }
      }
      if (!r.empty()) {
          sort(r.begin(), r.end(), SortCompare);
          r.erase(unique(r.begin(), r.end(), UniqueCompare), r.end());
      }
      return r;
  }
  */
};
