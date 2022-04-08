#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
#include "310-2.cpp"

int main() {
  Solution s;
  fstream fio;
  fio.open("a", ios::in);
  string str;
  std::getline(fio, str);
  vector<vector<int>> edges;
  std::string delim = ";";
  auto start = 0U;
  auto end = str.find(delim);
  vector<int> v(2);
  while (end != std::string::npos)
  {
    string t = str.substr(start, end - start);
    start = end + delim.length();
    end = str.find(delim, start);
    auto e = t.find(",");
    string s1 = t.substr(0, e);
    string s2 = t.substr(e + 1);
    v[0] = atoi(s1.data());
    v[1] = atoi(s2.data());
    edges.push_back(v);
  }
  {
    string t= str.substr(start);
    auto e = t.find(",");
    string s1 = t.substr(0, e);
    string s2 = t.substr(e + 1);
    v[0] = atoi(s1.data());
    v[1] = atoi(s2.data());
    edges.push_back(v);
  }
  cout << "count: " << edges.size() << endl;
  cout << "e[0] = [" << edges[0][0] << "," << edges[0][1] << "]" << endl;
  cout << "e[1] = [" << edges[1][0] << "," << edges[1][1] << "]" << endl;
  cout << "e[$] = [" << edges[edges.size()-1][0] << "," << edges[edges.size()-1][1] << "]" << endl;

  int n = edges.size() + 1;
  vector<int> r = s.findMinHeightTrees(n, edges);
  for (int i : r) {
    cout << i << ",";
  } cout << endl;

  return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
