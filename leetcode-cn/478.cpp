#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

class Solution {
 public:
  Solution(double radius, double x_center, double y_center)
      : r_(radius), x_(x_center), y_(y_center) {
    rr_ = r_ * r_;
    srand(time(NULL));
  }

  vector<double> randPoint() {
    while (true) {
      double x = (double)rand() / RAND_MAX * r_;
      double y = (double)rand() / RAND_MAX * r_;
      if (x * x + y * y <= rr_) {
        int t = rand() % 4;
        switch (t) {
          case 0:
            return {x_ + x, y_ + y};
          case 1:
            return {x_ + x, y_ - y};
          case 2:
            return {x_ - x, y_ + y};
          case 3:
            return {x_ - x, y_ - y};
        }
      }
    }
  }

 private:
  double r_, x_, y_, rr_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
