#include <string>
#include <cstring>
using namespace std;

class Solution {
public:
 string decodeMessage(string key, string message) {
   char a[26];
   memset(a, 0, sizeof(a));
   char k = 'a';
   for (char c : key) {
     if (c != ' ' && a[c - 'a'] == 0) {
       a[c - 'a'] = k++;
     }
   }
   int n = message.size();
   for (int i = 0; i < n; ++i) {
     char& c = message[i];
     if (c != ' ') {
       c = a[c - 'a'];
     }
   }
   return message;
 }
};
