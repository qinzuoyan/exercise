#include <iostream>
#include <string>

void number_to_letter(const char* numbers, int next_number_pos,
        char* letters, int next_letter_pos, int* count)
{
    if (!numbers[next_number_pos]) {
        letters[next_letter_pos] = '\0';
        if (*count > 0)
            std::cout << " ";
        std::cout << letters;
        (*count)++;
        return;
    }
    char ch = numbers[next_number_pos];
    if (ch >= '1' && ch <= '9') {
        letters[next_letter_pos] = 'a' + ch - '1';
        number_to_letter(numbers, next_number_pos + 1,
                letters, next_letter_pos + 1, count);
    }
    if (ch == '1') {
        char ch1 = numbers[next_number_pos + 1];
        if (ch1 >= '0' && ch1 <= '9') {
            letters[next_letter_pos] = 'j' + ch1 - '0';
            number_to_letter(numbers, next_number_pos + 2,
                    letters, next_letter_pos + 1, count);
        }
    }
    if (ch == '2') {
        char ch1 = numbers[next_number_pos + 1];
        if (ch1 >= '0' && ch1 <= '6') {
            letters[next_letter_pos] = 't' + ch1 - '0';
            number_to_letter(numbers, next_number_pos + 2,
                    letters, next_letter_pos + 1, count);
        }
    }
}

int number_to_letter(const std::string& numbers)
{
    char* buf = new char[numbers.size() + 1];
    int count = 0;
    number_to_letter(numbers.c_str(), 0, buf, 0, &count);
    delete []buf;
    return count;
}

int main(int argc, char** argv)
{
    std::string line;
    while (std::getline(std::cin, line)) {
        if (!line.empty()) {
            number_to_letter(line);
            std::cout << std::endl;
        }
    }
    return 0;
}

