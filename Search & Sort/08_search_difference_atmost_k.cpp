#include <iostream>

int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n) {
        if (arr[i] == x)
            return i;
        if (arr[i] - k <= x <= arr[i] + k)
            i++;
        else
            i += abs(x - arr[i]) / k;
    }

    return -1;
}
