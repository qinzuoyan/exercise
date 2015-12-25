#include "parse_kv.h"

#include <cctype>
#include <cstdlib>

// split string by delimiter to substr list
static void split_string(const std::string& str, const std::string& delim, std::list<std::string>* substr_list);

// parse key-value pair
static bool parse_key_value(const std::string& str, std::string* key, std::string* value);

// trim head and tail space character of string
static std::string trim_string(const std::string& str);

void parse_kv(const std::string& tag, std::list<std::pair<std::string, std::string> >* kv_list)
{
    if (tag.empty()) return;
    std::list<std::string> substr_list;
    split_string(tag, ",", &substr_list);
    for (std::list<std::string>::iterator it = substr_list.begin(); it != substr_list.end(); ++it) {
        std::string key, value;
        if (parse_key_value(*it, &key, &value)) {
            kv_list->push_back(std::make_pair(key, value));
        }
    }
}

void split_string(const std::string& str, const std::string& delim, std::list<std::string>* substr_list)
{
    if (str.empty()) return;
    if (delim.empty()) {
        substr_list->push_back(str);
        return;
    }
    std::string::size_type start = 0;
    while (true) {
        std::string::size_type pos = str.find(delim, start);
        if (pos == start) {
            start += delim.length();
            continue;
        }
        else if (pos == std::string::npos) {
            substr_list->push_back(str.substr(start));
            break;
        }
        else {
            substr_list->push_back(str.substr(start, pos - start));
            start = pos + delim.length();
        }
    }
}

bool parse_key_value(const std::string& str, std::string* key, std::string* value)
{
    if (str.empty()) return false;
    std::string::size_type pos = str.find(":");
    if (pos == std::string::npos) return false;
    *key = trim_string(str.substr(0, pos));
    if (key->empty()) return false;
    *value = trim_string(str.substr(pos + 1));
    return true;
}

std::string trim_string(const std::string& str)
{
    std::string::size_type start_pos = 0;
    std::string::size_type end_pos = str.length();
    while (start_pos != end_pos && isspace(str.at(start_pos))) ++start_pos;
    if (start_pos == end_pos) return "";
    --end_pos;
    while (isspace(str.at(end_pos))) --end_pos;
    return str.substr(start_pos, end_pos - start_pos + 1);
}
