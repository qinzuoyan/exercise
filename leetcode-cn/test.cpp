#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#include "LCP05.cpp"

int main() {
  Solution s;
  int n = 6;
  vector<vector<int>> leadership = { {1, 2}, {1, 6}, {2, 3}, {2, 5}, {1, 4} };
  vector<vector<int>> operations = { {1, 1, 500}, {2, 2, 50}, {3, 1}, {2, 6, 15}, {3, 1} };
  vector<int> r = s.bonus(n, leadership, operations);
  for (int i : r) {
    cout << i << "," << endl;
  }
  return 0;
}

