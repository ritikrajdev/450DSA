class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int _xor = 0;
        for (int num : nums)
            _xor ^= num;
        
        // xor - 1 flips all right bits upto rightmost set bit
        // flipping them all again to remove all bits on left of set bit
        int last_set_bit = _xor & (~(_xor - 1));
        int n1 = 0, n2 = 0;
        for (int num: nums) {
            if (num & last_set_bit)
                n1 ^= num;
            else
                n2 ^= num;
        }
        
        if (n1 > n2)
            swap(n1, n2);
        
        return {n1, n2};
    }
};
