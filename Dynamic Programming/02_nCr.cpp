// Bottom Up

const int mod = 1e9 + 7;

class Solution{
    vector<vector<int>> t;
public:
    Solution() {
        t = vector<vector<int>>(1002, vector<int>(1002, -1));
    }
    
    int nCr(int n, int r){
        // Invalid Inputs
        if (n < r) return 0;
        if (n == 0) return 0;

        // Valid Inputs
        if (n == r || r == 0) return 1;
        
        if (t[n][r] != -1)
            return t[n][r];
        
        return t[n][r] = (nCr(n-1, r-1) + nCr(n-1, r)) % mod;
    }
};


// Top Down
class Solution{
public:
    int nCr(int N, int R){
        vector<vector<int>> t (N+1, vector<int>(R+1));
        
        for (int n = 0; n <= N; n++)
            t[n][0] = 1;
        
        for (int n = 1; n <= N; n++)
            for (int r = 1; r <= R; r++)
                t[n][r] = (t[n-1][r-1] + t[n-1][r]) % mod; // see we only need last row

        return t[N][R];
    }
};

// Space Optimisation
class Solution{
public:
    int nCr(int N, int R){
        vector<int> t(R+1);
        t[0] = 1;
        
        for (int n = 1; n <= N; n++) {
            int last_t_of_r_minus_1 = 1;
            for (int r = 1; r <= min(n, R); r++) {
                int temp = t[r];
                t[r] = (t[r] + last_t_of_r_minus_1) % mod;
                last_t_of_r_minus_1 = temp;
            }
        }

        return t[R];
    }
};
