#include <vector>
using namespace std;

int find(int arr[], int n, int x, bool findFirst) {
    int l = 0, h = n - 1;
    int i = -1;

    while (l <= h) {
        int m = l + (h - l) / 2;
        if (arr[m] < x)
            l = m + 1;
        else if (arr[m] > x)
            h = m - 1;
        else {
            i = m;
            findFirst ? h = m - 1 : l = m + 1;
        }
    }

    return i;
}

vector<int> find(int arr[], int n, int x) {
    return {find(arr, n, x, true), find(arr, n, x, false)};
}
