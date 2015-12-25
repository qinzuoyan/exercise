#include "include_guard.h"
#include <sstream>
#include <cctype>

std::string include_guard_str(const std::string& name)
{
    std::ostringstream oss;
    oss << "_";
    bool last_upper = false;
    for (size_t i = 0; i < name.size(); ++i) {
        if (isupper(name[i])) {
            if (last_upper && ((i < name.size() - 1) || !islower(name[i+1]))) {
                oss << "_";
            }
            last_upper = true;
        }
        if (name[i] == '.') {
            oss << "_";
        }
        else if (islower(name[i])) {
            oss << static_cast<char>(toupper(name[i]));
        }
        else {
            oss << name[i];
        }
    }
    oss << "_";
    return oss.str();
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
