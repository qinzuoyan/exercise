#include <cstdio>
#include "number_to_letter.h"

int main(int argc, char** argv)
{
    if (argc <= 1) {
        fprintf(stderr, "USAGE: %s <number_string>\n", argv[0]);
        return -1;
    }
    int count = number_to_letter(argv[1]);
    if (count == 0) {
        fprintf(stderr, "Can not convert.\n");
        return -1;
    }
    fprintf(stdout, "Total count: %d\n", count);
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
