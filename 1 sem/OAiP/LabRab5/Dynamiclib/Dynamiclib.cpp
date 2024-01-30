#include <iostream>
#include "Header.h"
int max(int* arr, int left_bound, int right_bound)
{
    int n = right_bound - left_bound;

    int left_max, right_max;
    if (n > 3)
    {
        left_max = max(arr, left_bound, left_bound + n / 3);
        right_max = max(arr, right_bound - n / 3, right_bound);
    }
    else
    {
        left_max = arr[left_bound];
        right_max = arr[left_bound + 1] > arr[left_bound + 2]
            ? arr[left_bound + 1] : arr[left_bound + 2];
    }

    return left_max > right_max ? left_max : right_max;
}