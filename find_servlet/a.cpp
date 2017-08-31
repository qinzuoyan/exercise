#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <map>

typedef int Handler;
#define InvalidHandler 0
typedef std::map<std::string, Handler> HandlerMap;

Handler find_handler(const HandlerMap& handler_map, const std::string& path)
{
    if (path.empty() || path[0] != '/') {
        return InvalidHandler;
    }
    Handler ret = InvalidHandler;
    size_t path_size = path.size();
    size_t cur_pos = 0;
    while (cur_pos < path_size) {
        cur_pos = path.find('/', cur_pos + 1);
        if (cur_pos == std::string::npos) {
            HandlerMap::const_iterator find = handler_map.find(path);
            if (find != handler_map.end()) {
                ret = find->second;
            }
            break;
        }
        std::string sub_path= path.substr(0, cur_pos);
        HandlerMap::const_iterator find = handler_map.lower_bound(sub_path);
        if (find == handler_map.end())
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

int main(int argc, char** argv)
{
    std::string line;
    HandlerMap handler_map;
    while (std::getline(std::cin, line)) {
        if (line.empty())
            break;
        size_t pos = line.find(" ");
        if (pos != std::string::npos) {
            std::string path = line.substr(0, pos);
            int id = atoi(line.data() + pos + 1);
            handler_map[path] = id;
        }
    }
    while (std::getline(std::cin, line)) {
        std::cout << find_handler(handler_map, line) << std::endl;
    }
    return 0;
}
