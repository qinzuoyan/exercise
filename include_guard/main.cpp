#include "include_guard.h"
#include <iostream>

int main(int argc, char** argv)
{
    if (argc == 1)
    {
        std::cout << "Usage: " << argv[0] << " [name]..." << std::endl;
        return 0;
    }
    for (int i = 1; i < argc; ++i)
    {
        std::cout << argv[i] << " --> " << include_guard_str(argv[i]) << std::endl;
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
