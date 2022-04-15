#include <string>
#include <vector>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Constructor initializes an empty nested list.
  NestedInteger() : _is_i(false), _i(0) {}

  // Constructor initializes a single integer.
  NestedInteger(int value) : _is_i(true), _i(value) {}

  // Return true if this NestedInteger holds a single integer, rather than a
  // nested list.
  bool isInteger() const { return _is_i; }

  // Return the single integer that this NestedInteger holds, if it holds a
  // single integer The result is undefined if this NestedInteger holds a nested
  // list
  int getInteger() const { return _i; }

  // Set this NestedInteger to hold a single integer.
  void setInteger(int value) {
    _is_i = true;
    _i = value;
    _v.clear();
  }

  // Set this NestedInteger to hold a nested list and adds a nested integer to
  // it.
  void add(const NestedInteger& ni) { _v.push_back(ni); }

  // Return the nested list that this NestedInteger holds, if it holds a nested
  // list The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger>& getList() const { return _v; }

 private:
  bool _is_i;
  int _i;
  vector<NestedInteger> _v;
};

class Solution {
 public:
  void parse(const string& s, int& i, NestedInteger& ni) {
    if (s[i] != '[') {
      char *endptr;
      ni.setInteger(strtol(s.data() + i, &endptr, 10));
      i = endptr - s.data();
    } else { // s[i] == '['
      i++;
      while (s[i] != ']') {
        NestedInteger sub;
        parse(s, i, sub);
        ni.add(sub);
        if (s[i] == ',')
          i++;
      }
      i++;
    }
  }

  NestedInteger deserialize(string s) {
    NestedInteger ni;
    int i = 0;
    parse(s, i, ni);
    return ni;
  }
};
