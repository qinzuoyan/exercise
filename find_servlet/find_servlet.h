#ifndef  __FIND_SERVLET_H_
#define  __FIND_SERVLET_H_

#include <string>
#include <map>

typedef void* Servlet;
#define InvalidServlet NULL
typedef std::map<std::string, Servlet> ServletMap;

// "servlet_map" is a map from path to Servlet, the path maybe:
//    /
//    /a
//    /a/b
//    /a/b/c
//    /b
//    ... ...
//
// return InvalidServlet if not found
// "search_map_count" gives how many times seaching in "servlet_map"
Servlet find_servlet(const ServletMap& servlet_map,
        const std::string& path, int* search_map_count);

#endif  //__FIND_SERVLET_H_

/* vim: set ts=4 sw=4 sts=4 tw=100 */
