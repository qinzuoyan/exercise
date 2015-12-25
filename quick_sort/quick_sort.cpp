#include <stdio.h>
#include <algorithm>

void swap(int array[], int i, int j)
{
    if (i != j) {
        int t = array[i];
        array[i] = array[j];
        array[j] = t;
    }
}

void select_sort(int array[], int start, int end)
{
    if (start >= end)
        return;
    for (int i = start; i < end; ++i) {
        int m = i;
        for (int j = i+1; j <= end; ++j) {
            if (array[j] < array[m])
                m = j;
        }
        swap(array, i, m);
    }
}

int choose_pivot(int array[], int start, int end)
{
    return (start + end) / 2;
}

void quick_sort(int array[], int start, int end)
{
    if (end - start <= 5) {
        select_sort(array, start, end);
        return;
    }
    swap(array, start, choose_pivot(array, start, end));
    int p = array[start];
    int i = start;
    int j = end;
    while (i < j) {
        while (i < j && array[j] >= p) j--;
        if (i < j) array[i++] = array[j];
        while (i < j && array[i] <= p) i++;
        if (i < j) array[j--] = array[i];
    }
    if (i != start) array[i] = p;
    // WARNING:
    // - forget call quick_sort recursively.
    // - maybe: (i-1) < start
    // - maybe: (i+1) > end
    quick_sort(array, start, i-1);
    quick_sort(array, i+1, end);
}

void print(int array[], int start, int end)
{
    for (int i = start; i <= end; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

#define N 100
int main()
{
    int array[N];
    for (int i = 0; i < N; ++i) {
        array[i] = i;
    }
    print(array, 0, N - 1);
    std::random_shuffle(array, array + N);
    print(array, 0, N - 1);
    quick_sort(array, 0, N - 1);
    print(array, 0, N - 1);
    return 0;
}

/* vim: set ts=4 sw=4 sts=4 tw=100 */
