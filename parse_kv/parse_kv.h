#ifndef  __PARSE_KV_H_
#define  __PARSE_KV_H_

#include <string>
#include <list>
#include <utility>

// Parse key-value from data, the data is in the following format:
//   k1:v1,k2:v2, ... ,kn:vn
void parse_kv(const std::string& data, std::list<std::pair<std::string, std::string> >* kv_list);

#endif  //__PARSE_KV_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
