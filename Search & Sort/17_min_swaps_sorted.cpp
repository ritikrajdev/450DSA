#include <vector>
#include <algorithm>

using namespace std;

class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    int cnt = 0;

	    vector<pair<int, int>> v;
	    for (int i = 0; i < nums.size(); i++)
	        v.push_back({nums[i], i});
	    sort(v.begin(), v.end());
	    // Basically sorted, will convert it back to original using swaps
	    
	    for (int i = 0; i < v.size(); i++) {
            if (i == v[i].second)
                continue;
            
            swap(v[i], v[v[i].second]);
            cnt++;
            if (v[i].second != i)
                i--;
	    }
	    
	    return cnt;
	}
};
