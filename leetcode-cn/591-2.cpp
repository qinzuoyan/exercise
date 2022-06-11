#include <cctype>
#include <cstring>
#include <stack>
#include <string>
using namespace std;

class Solution {
 public:
  static const int TAG_NAME_MAX_LEN = 9;

  enum TagType {
    InvalidType = 0,
    TagBegin = 1,
    TagEnd = 2,
    CDateBegin = 3,
  };

  struct Slice {
    const char *str;
    int len;
    Slice() : str(nullptr), len(0) {}
    Slice(const Slice &o) : str(o.str), len(o.len) {}
    void assign(const char *s, int l) { str = s, len = l; }
    friend bool operator==(const Slice &x, const Slice &y) {
      return x.len == y.len && strncmp(x.str, y.str, x.len) == 0;
    }
    friend bool operator!=(const Slice &x, const Slice &y) { return !(x == y); }
  };

  struct T {
    TagType type;
    Slice name;
    T(TagType t, const Slice &n) : type(t), name(n) {}
  };

  TagType checkTagType(const char *str, const char *end, Slice &name,
                       int &used) {
    if (end - str < 3) return InvalidType;
    if (*str != '<') return InvalidType;
    if (strncmp(str, "<![CDATA[", 9) == 0) {
      used = 9;
      return CDateBegin;
    }
    ++str;
    TagType ret = TagBegin;
    if (*str == '/') {
      ++str;
      ret = TagEnd;
    }
    const char *n = str;
    while (str - n < TAG_NAME_MAX_LEN && str < end && isupper(*str)) ++str;
    if (n == str || *str != '>') return InvalidType;
    name.assign(n, str - n);
    used = name.len + (ret == TagBegin ? 2 : 3);
    return ret;
  }

  bool isValid(string code) {
    const char *str = code.data(), *end = code.data() + code.size();
    stack<T> s;
    Slice name;
    int used = 0;
    if (checkTagType(str, end, name, used) != TagBegin) return false;
    s.emplace(TagBegin, name);
    str += used;
    while (s.size() && str < end) {
      if (*str != '<') {
        ++str;
      } else {
        int tag_type = checkTagType(str, end, name, used);
        if (tag_type == InvalidType) return false;
        if (tag_type == TagBegin) {
          s.emplace(TagBegin, name);
          str += used;
        } else if (tag_type == TagEnd) {
          if (s.empty() || s.top().name != name) return false;
          s.pop();
          str += used;
        } else {  // tag_type == CDateBegin
          const char *cdata_end_pos = strstr(str + 9, "]]>");
          if (cdata_end_pos == nullptr) return false;
          str = cdata_end_pos + 3;
        }
      }
      if (s.empty()) return str == end;
    }
    return s.empty() && str == end;
  }
};
