#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    int num_bits_a = 0;
    while (a) {
        num_bits_a++;
        a = a & (a-1);
    }
    
    int num_bits_b = 0;
    while (b) {
        num_bits_b ++;
        b = b & (b-1);
    }
    
    return num_bits_a > num_bits_b;
}

class Solution{
    public:
    void sortBySetBitCount(int arr[], int n)
    {
        stable_sort(arr, arr+n, compare);
    }
};
