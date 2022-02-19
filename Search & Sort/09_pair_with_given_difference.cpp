#include <iostream>
#include <unordered_map>

using namespace std;

bool findPair(int arr[], int n, int x){
    unordered_map<int, bool> ump;
    x = abs(x);

    for (int i = 0; i < n; i++) {
        if (ump[arr[i] + x] || ump[arr[i] - x])
            return true;
        ump[arr[i]] = true;
    }

    return false;
}
