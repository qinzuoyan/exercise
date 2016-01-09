#include <find_servlet.h>
#include <cstring>

Servlet find_servlet(const ServletMap& servlet_map,
        const std::string& path, int* search_map_count)
{
    *search_map_count = 0;
    if (path.empty() || path[0] != '/') {
        return InvalidServlet;
    }
    if (path == "/") {
        ServletMap::const_iterator find = servlet_map.find("/");
        ++(*search_map_count);
        return find == servlet_map.end() ? InvalidServlet : find->second;
    }
    Servlet ret = NULL;
    size_t path_size = path.size();
    size_t cur_pos = 0;
    while (cur_pos < path_size) {
        cur_pos = path.find('/', cur_pos + 1);
        if (cur_pos == std::string::npos) {
            ServletMap::const_iterator find = servlet_map.find(path);
            ++(*search_map_count);
            if (find != servlet_map.end()) {
                ret = find->second;
            }
            break;
        }
        std::string sub_path= path.substr(0, cur_pos);
        ServletMap::const_iterator find = servlet_map.lower_bound(sub_path);
        ++(*search_map_count);
        if (find == servlet_map.end())
            break;
        const std::string& find_path = find->first;
        size_t find_path_size = find_path.size();
        if (find_path_size <= path_size
                && strncmp(path.data(), find_path.data(), find_path_size) == 0
                && (find_path_size == path_size || path[find_path_size] == '/')) {
            ret = find->second;
            cur_pos = find_path_size;
        }
        else {
            break;
        }
    }
    return ret;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
