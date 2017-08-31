#include <iostream>
#include <sstream>
#include <cctype>

std::string include_guard_str(const std::string& name)
{
    std::ostringstream oss;
    oss << "_";
    bool last_upper = false;
    bool last_lower = false;
    bool last_digit = false;
    for (size_t i = 0; i < name.size(); ++i) {
        if (isupper(name[i])) {
            if (last_lower || last_digit || last_upper && i + 1 < name.size() && islower(name[i + 1]))
                oss << "_";
        }
        if (isdigit(name[i])) {
            if (last_upper || last_lower)
                oss << "_";
        }
        if (islower(name[i])) {
            if (last_digit)
                oss << "_";
        }
        last_upper = isupper(name[i]);
        last_lower = islower(name[i]);
        last_digit = isdigit(name[i]);
        if (name[i] == '.')
            oss << "_";
        else if (islower(name[i]))
            oss << static_cast<char>(toupper(name[i]));
        else
            oss << name[i];
    }
    oss << "_";
    return oss.str();
}

int main(int argc, char** argv)
{
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty())
            std::cout << include_guard_str(line) << std::endl;
    }
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
