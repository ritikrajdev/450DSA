#include <vector>

using namespace std;

class Solution {
  public:
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n) {
        unsigned long long product = 1;
        int num_zeros = 0;

        for (auto num : nums)
            if (num != 0)
                product *= num;
            else
                num_zeros++;
        vector<long long int> v = nums;
        for (auto &x : v)
            if (num_zeros > 1)
                x = 0;
            else if (num_zeros == 1)
                x = x == 0 ? product : 0;
            else
                x = product / x;
        return v;
    }
};
