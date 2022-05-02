#include <string>
#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;


//////////////////////////////////////////
// error in case: "<A><A>456</A>  <A> 123  !!  <![CDATA[]]>  123 </A>   <A>123</A></A>"
//      expected: true
//          real: false
//////////////////////////////////////////



#define BEGIN_CHECK(name)                                               \
  char *end = str + len, end_back = str[len];                           \
  *end = '\0';                                                          \
  if (print) {                                                          \
    for (int i = 0; i < depth; ++i) cout << "  ";                       \
    cout << ">>[" << __FUNCTION__ << "]: " << string(str, len) << endl; \
    ++depth;                                                            \
  }

#define RETURN_FAILURE                                                  \
  do {                                                                  \
    if (print) {                                                        \
      --depth;                                                          \
      for (int i = 0; i < depth; ++i) cout << "  ";                     \
      cout << "<<[" << __FUNCTION__ << "]: ERROR: " << string(str, len) \
           << endl;                                                     \
    }                                                                   \
    *end = end_back;                                                    \
    return -1;                                                          \
  } while (0)

#define RETURN_SUCCESS(len)                             \
  do {                                                  \
    if (print) {                                        \
      --depth;                                          \
      for (int i = 0; i < depth; ++i) cout << "  ";     \
      cout << "<<[" << __FUNCTION__ << "]: OK" << endl; \
    }                                                   \
    *end = end_back;                                    \
    return len;                                         \
  } while (0)

class Solution {
 public:
  static const int TAG_NAME_MAX_LEN = 9;

  static bool print;
  static int depth;

  // return cdata start len
  int checkCData(char *str, int len) {
    BEGIN_CHECK(checkCData);
    if (strncmp(str, "<![CDATA[", 9) != 0) RETURN_FAILURE;
    char *cdata_end_pos = strstr(str + 9, "]]>");
    if (cdata_end_pos == nullptr) RETURN_FAILURE;
    RETURN_SUCCESS(cdata_end_pos - str + 3);
  }

  // return tag content len
  int checkTagContent(char *str, int len) {
    BEGIN_CHECK(checkTagContent);
    int ret_len;
    while (str < end) {
      if (*str != '<')
        ++str;
      else if ((ret_len = checkCData(str, end - str)) >= 0)
        str += ret_len;
      else if ((ret_len = checkTag(str, end - str)) >= 0)
        str += ret_len;
      else
        RETURN_FAILURE;
    }
    RETURN_SUCCESS(len);
  }

  // return tag len
  int checkTag(char *str, int len) {
    BEGIN_CHECK(checkTag);
    if (len < 7) RETURN_FAILURE;
    char buf[TAG_NAME_MAX_LEN + 4] = {'<', '/'};
    char *name = buf + 2;
    if (*str++ != '<') RETURN_FAILURE;
    while (name - buf - 2 < TAG_NAME_MAX_LEN && str < end && isupper(*str))
      *name++ = *str++;
    if (name == buf + 2 || str == end || *str++ != '>') RETURN_FAILURE;
    *name++ = '>';
    *name = '\0';
    int name_len = name - buf;
    char *tag_end_pos = strstr(str, buf), *t = nullptr;
    while (tag_end_pos && (t = strstr(tag_end_pos + name_len, buf)))
      tag_end_pos = t;
    if (tag_end_pos == nullptr) RETURN_FAILURE;
    int tag_content_len = checkTagContent(str, tag_end_pos - str);
    if (tag_content_len < 0) RETURN_FAILURE;
    RETURN_SUCCESS(tag_content_len + name_len + name_len - 1);
  }

  bool isValid(string code) {
    print = true;
    depth = 0;
    return checkTag(&code[0], code.size()) == (int)code.size();
  }
};

bool Solution::print = false;
int Solution::depth = 0;

