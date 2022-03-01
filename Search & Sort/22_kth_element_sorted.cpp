#include <iostream>

using namespace std;

class Solution {
  public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k) {
        int i = 0, j = 0, c = 0;
        if (k > n + m)
            return -1;

        while (c < k && i < n && j < m) {
            if (arr1[i] <= arr2[j])
                i++;
            else
                j++;

            c++;
        }

        while (c < k && i < n)
            i++, c++;
        while (c < k && j < m)
            j++, c++;

        if (i <= n && j <= m)
            return max(arr1[i - 1], arr2[j - 1]);

        if (i <= n)
            return arr1[i - 1];

        return arr2[j - 1];
    }
};
