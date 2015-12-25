#include "find_dup.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    if (argc == 1) {
        fprintf(stdout, "Usage: %s [number]...\n", argv[0]);
        return 0;
    }
    int n = argc - 1;
    int* arr = new int[n];
    for (int i = 1; i < argc; ++i) {
        arr[i-1] = atoi(argv[i]);
    }
    int dup = find_dup(arr, n);
    if (dup == -1) {
        fprintf(stdout, "No dup found\n");
        return -1;
    }
    fprintf(stdout, "Dup: %d\n", dup);
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
