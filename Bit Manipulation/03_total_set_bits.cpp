class Solution{
    public:
    
    int countSetBits(int n)
    {
        if (n == 0)
            return 0;

        int k = log2(n);
        int c = pow(2, k);

        return (c*k / 2) + (n-c+1) + countSetBits(n-c);
    }
};
