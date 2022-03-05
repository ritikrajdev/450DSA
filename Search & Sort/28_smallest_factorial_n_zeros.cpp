class Solution {
    public:
    bool numZerosGreaterX(int n, int x) {
        int c = 0;
        while (n) {
            c += n/5;
            n /= 5;
        }
        return c >= x; 
    }

    int findNum(int n) {
        int l = 0, h = 5*n;
        while (l <= h) {
            int m = l + (h-l)/2;
            if (numZerosGreaterX(m, n))
                h = m - 1;
            else
                l = m + 1;
        }
        return l;
    }
};
