#include <vector>

using namespace std;

class Solution{
public:
	vector<int> valueEqualToIndex(int arr[], int n) {
	    vector<int> res;
	    res.reserve(n);
	    for (int i = 0; i < n; i++)
	        if (i + 1 == arr[i])
	            res.push_back(i+1);
	    return res;
	}
};
