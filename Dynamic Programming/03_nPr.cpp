const int mod = 1e9 + 7;
int P(int n, int k) {
    long long p = 1;
    for (int i = n; i >= n - k + 1; i--) {
        p *= i;
        p %= mod;
    }
    return p;
}

// O(n-k)
