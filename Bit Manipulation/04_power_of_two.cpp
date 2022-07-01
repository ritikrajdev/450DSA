class Solution{
    public:
    bool isPowerofTwo(long long n){
	// n & n-1 will be zero as the & with flip part will give all the left part and it must be zero because divisble by two is of type 00100
	// i.e. all left zero before the last set bit
        return n != 0 && (n & (n - 1)) == 0;
    }
};
