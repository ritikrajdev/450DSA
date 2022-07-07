const int mod = 1e9 + 7;
class Solution{
	vector<vector<int>> t;
	public:
	Solution() {
		t = vector<vector<int>> (1002, vector<int> (1002, -1));
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    if (sum == 0)
	        return 1;

   	    if (sum < 0 || n == 0)
	        return 0;

		if (t[n][sum] != -1)
			return t[n][sum];

        return t[n][sum] = (perfectSum(arr, n-1, sum) + perfectSum(arr, n-1, sum-arr[n-1])) % mod;
	}
};
