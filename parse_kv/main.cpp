#include <cstdio>
#include "parse_kv.h"

int main(int argc, char** argv)
{
    if (argc <= 1) {
        fprintf(stderr, "USAGE: %s <kv_list>\n", argv[0]);
        return -1;
    }
    std::list<std::pair<std::string, std::string> > kv_list;
    parse_kv(argv[1], &kv_list);
    for (std::list<std::pair<std::string, std::string> >::iterator it = kv_list.begin();
            it != kv_list.end(); ++it) {
        fprintf(stderr, "%s -> %s\n", it->first.c_str(), it->second.c_str());
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
