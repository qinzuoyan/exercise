#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

struct T {
  int v;
  void print() {
    std::cout << v << endl;
  }
};

void f(T& t) {
  t.print();
}

int main() {
  T* p = nullptr;
  f(*p);
  return 0;
}
