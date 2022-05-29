#include <string>
#include <cstring>
#include <cctype>
using namespace std;

class Solution {
public:
 bool checkIPv4(const char* s) {
   int c = 0;
   const char* b = s;
   while (*s) {
     if (isdigit(*s)) {
       if (s - b == 1 && *b == '0')
         return false;
       else if (s - b == 2 && strncmp(b, "255", 3) > 0)
         return false;
       else if (s - b == 3)
         return false;
       ++s;
     } else if (*s == '.') {
       if (s == b) return false;
       ++c;
       if (c == 4) return false;
       ++s;
       b = s;
     } else {
       return false;
     }
   }
   if (s != b) ++c;
   return c == 4;
 }
 bool checkIPv6(const char* s) {
   int c = 0;
   const char* b = s;
   while (*s) {
     if (isdigit(*s) || (*s >= 'a' && *s <= 'f') || (*s >= 'A' && *s <= 'F')) {
       if (s - b == 4) return false;
       ++s;
     } else if (*s == ':') {
       if (s == b) return false;
       ++c;
       if (c == 8) return false;
       ++s;
       b = s;
     } else {
       return false;
     }
   }
   if (s != b) ++c;
   return c == 8;
 }
 string validIPAddress(string queryIP) {
   if (queryIP.find_first_of('.') && checkIPv4(queryIP.data()))
     return "IPv4";
   else if (queryIP.find_first_of(':') && checkIPv6(queryIP.data()))
     return "IPv6";
   else
     return "Neither";
 }
};
