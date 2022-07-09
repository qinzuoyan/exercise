#include <string>
#include <unordered_map>
#include <functional>
using namespace std;

class Solution {
 private:
  std::hash<string> str_hash;
  std::unordered_map<string, string> url_map;

 public:
  string hashToStr(size_t h) {
    char a[6];
    for (int i = 0; i < 6; ++i) {
      size_t r = h & 0x3F;
      if (r < 10) {
        a[i] = '0' + r;
      } else if (r < 36) {
        a[i] = 'a' + (r - 10);
      } else if (r < 62) {
        a[i] = 'A' + (r - 36);
      } else {
        a[i] = 'a';
      }
      h >>= 6;
    }
    return string(a, 6);
  }

  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    size_t h = str_hash(longUrl);
    string s;
    while (true) {
      s = hashToStr(h);
      auto f = url_map.insert(std::make_pair(s, longUrl));
      if (f.second) break;
      h++;
    }
    return "http://tinyurl.com/" + s;
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string s = shortUrl.substr(19);
    return url_map[s];
  }
};
