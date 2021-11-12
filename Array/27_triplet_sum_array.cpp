#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "general.h"

using namespace std;

namespace ritik {
	// May Not follow my naming convention coz did it on online editor :tear:
	bool find2Numbers(int A[], int n, int target, int leave_index=-1) {
        int i = 0, j = n - 1;
        
        while (i < j) {
            if (i == leave_index) i++;
            if (j == leave_index) j--;
            
            if (A[i] +A[j] == target)
                return true;
            else if (A[i]+A[j] > target)
                j--;
            else i++;
        }
        
        return false;
    }

    bool find3Numbers(int A[], int n, int X)
    {
        sort(A, A+n);
        for (int i = 0; i < n; i++) {
            if (find2Numbers(A, n, X-A[i], i))
                return true;
        }
        return false;
    }
}

int main() {
	int arr[] {1 ,4 ,45 ,6 ,10 ,8};
	cout << ritik::find3Numbers(arr, 6, 13);
	return 0;
}

