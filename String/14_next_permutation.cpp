#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> nextPermutation(int N, vector<int> arr) {
        int i = N - 2, j = N - 1;

        for (; i >= 0; i--)
            if (arr[i + 1] > arr[i])
                break;

        if (i >= 0) {
            for (; j > i; j--)
                if (arr[j] > arr[i])
                    break;
            if (j > i)
                swap(arr[j], arr[i]);
        }

        reverse(arr.begin() + i + 1, arr.end());
        return arr;
    }
};
