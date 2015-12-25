#include "number_to_letter.h"
#include <cstdio>
#include <cstring>

static int number_to_letter(const char* numbers, int next_number_pos,
        char* letters, int next_letter_pos);

int number_to_letter(const char* numbers)
{
    size_t len = strlen(numbers);
    char* buf = new char[len + 1];
    int count = number_to_letter(numbers, 0, buf, 0);
    delete []buf;
    return count;
}

int number_to_letter(const char* numbers, int next_number_pos,
        char* letters, int next_letter_pos)
{
    if (!numbers[next_number_pos]) {
        letters[next_letter_pos] = '\0';
        fprintf(stdout, "%s\n", letters);
        return 1;
    }
    char ch = numbers[next_number_pos];
    int count = 0;
    if (ch >= '1' && ch <= '9') {
        letters[next_letter_pos] = 'a' + ch - '1';
        count += number_to_letter(numbers, next_number_pos + 1,
                letters, next_letter_pos + 1);
    }
    if (ch == '1') {
        char ch1 = numbers[next_number_pos + 1];
        if (ch1 >= '0' && ch1 <= '9') {
            letters[next_letter_pos] = 'j' + ch1 - '0';
            count += number_to_letter(numbers, next_number_pos + 2,
                    letters, next_letter_pos + 1);
        }
    }
    if (ch == '2') {
        char ch1 = numbers[next_number_pos + 1];
        if (ch1 >= '0' && ch1 <= '6') {
            letters[next_letter_pos] = 't' + ch1 - '0';
            count += number_to_letter(numbers, next_number_pos + 2,
                    letters, next_letter_pos + 1);
        }
    }
    return count;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
