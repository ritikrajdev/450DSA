#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int l = 0, h = arr.size() - 1;
        
        int m;
        while (l <= h) {
            m = l + (h - l)/2;
            if (arr[m] == target) return m;
            else if (arr[l] <= arr[m]) {
                if (target < arr[m] && target >= arr[l]) h = m - 1;
                else l = m + 1;
            }
            else if (arr[m] < arr[h]){
                if (target > arr[m] && target <= arr[h]) l = m + 1;
                else h = m - 1;
            } else break;
        }
        return -1;
    }
};
