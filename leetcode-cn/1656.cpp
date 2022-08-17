#include <string>
#include <vector>
using namespace std;

class OrderedStream {
  int max;
  int ptr;
  vector<string> vec;
public:
    OrderedStream(int n) : max(n), ptr(1) {
      vec.resize(max + 1);
    }
    
    vector<string> insert(int idKey, string value) {
      vec[idKey] = value;
      vector<string> r;
      if (idKey == ptr) {
        while (ptr <= max && vec[ptr].size()) {
          r.push_back(vec[ptr]);
          ++ptr;
        }
      }
      return r;
    }
};
