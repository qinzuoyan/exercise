#include "find_dup.h"
#include <assert.h>

static void swap(int arr[], int i, int j)
{
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int find_dup(int arr[], int n)
{
    for (int i = 0; i < n; ++i) {
        int k = arr[i];
        assert(k >= 0 && k < n);
        while (k > i) {
            if (arr[k] == k) {
                return k;
            }
            else {
                swap(arr, i, k); 
                k = arr[i];
            }
        }
        if (k < i) {
            return k;
        }
    }
    return -1;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
