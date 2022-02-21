#include <algorithm>

using namespace std;

class Solution{
public:
	void merge(int arr1[], int arr2[], int n, int m) {
	    int i = 0, j = 0, k = n-1;
	    while (i < n && j < m) {
	        if (arr1[i] <= arr2[j]) i++;
	        else swap(arr1[k--], arr2[j++]);
	    }
	    sort(arr1, arr1+n);
	    sort(arr2, arr2+m);
	}
};
