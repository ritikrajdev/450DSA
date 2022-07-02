class Solution
{
    public:
    long long positive_division(long long dividend, long long divisor) {
        if (dividend < divisor)
            return 0;
        
        if (dividend == divisor)
            return 1;
        
        long long x = divisor, c = 0;
        while (dividend >= x) {
            x = x << 1;
            c++;
        }
        return (1<<(c-1)) + positive_division(dividend - (x>>1), divisor);
    }
    
    long long divide(long long dividend, long long divisor) 
    {
        // Binary Search
        // divide by 2 means >> 1
        // pow(2, n) means 1 << n
        
        long long ans = positive_division(abs(dividend), abs(divisor));
        ans = (dividend > 0) ^ (divisor > 0) ? -ans : ans;
        
        return ans;
    }
};
