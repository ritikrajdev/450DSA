// Recursive
class Solution {
    vector<vector<long long>> t;

  public:
    Solution() {
        t = vector<vector<long long>>(1002, vector<long long>(1002, -1));
    }

    long long int count(int S[], int m, int n) {
        if (n == 0)
            return 1;

        if (m == 0 || n < 0)
            return 0;

        if (t[n][m] != -1)
            return t[n][m];

        return t[n][m] = count(S, m, n - S[m - 1]) + count(S, m - 1, n);
    }
};

// Top Down
long long int count(int S[], int m, int n) {
    vector<vector<long long>> t(n + 1, vector<long long>(m + 1));

    for (int j = 0; j <= m; j++)
        t[0][j] = 1;

    for (int cents = 1; cents <= n; cents++) {
        for (int coin_num = 1; coin_num <= m; coin_num++) {
            t[cents][coin_num] = t[cents][coin_num - 1];
            if (S[coin_num - 1] <= cents)
                t[cents][coin_num] += t[cents - S[coin_num - 1]][coin_num];
        }
    }

    return t[n][m];
}

// Space Optimized
class Solution {
  public:

    long long int count(int S[], int m, int n) {
        vector<long long> t(n+1);
        
        t[0] = 1;

        for (int coin_num = 1; coin_num <= m; coin_num++)    
            for (int cents = 1; cents <= n; cents++)
                if (cents >= S[coin_num-1])
                    t[cents] += t[cents - S[coin_num-1]];
        
        return t[n];
    }
};
