#include <vector>

using namespace std;

class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> t(n+1, -1);
        t[0] = 0;
        t[1] = arr[0];

        for (int i = 2; i <= n; i++) {
            t[i] = max(arr[i-1] + t[i-2], t[i-1]);
        }
        return t[n];
    }
};
