#include <vector>

using namespace std;

class Solution {
    vector<int> nums;
    int n;
    int k;
    
    vector<vector<int>> memory;

    int solve(int k, int i=0) {
        if (i == n-1)
            return memory[i][k] = nums[i] < k ? 0 : k*k;
        
        if (memory[i][k] != -1)
            return memory[i][k];

        if (k == this->k)
            return memory[i][k] = solve(k-nums[i], i+1);
        else if (nums[i] < k)
            return memory[i][k] = min(solve(k-nums[i]-1, i+1), solve(this->k - nums[i], i+1) + k*k);
        else
            return memory[i][k] = solve(this->k - nums[i], i+1) + k*k;
    }
public:
    int solveWordWrap(vector<int>nums, int k)
    {
        this->nums = nums;
        this->k = k;
        this->n = nums.size();
        this->memory = vector<vector<int>> (501, vector<int>(1501, -1));
        return solve(k);
    }
};
