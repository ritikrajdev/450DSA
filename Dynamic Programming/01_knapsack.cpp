// Bottom Up
class Solution
{
    vector<vector<int>> t;
    public:
    Solution() {
        t = vector<vector<int>>(1002, vector<int>(1002, -1));
    }
    int knapSack(int w, int wt[], int val[], int n) {
        if (n == 0 || w == 0)
            return 0;
        
        if (t[w][n] != -1)
            return t[w][n];
        
        int max_wt = knapSack(w, wt, val, n-1);
        if (wt[n-1] <= w)
            max_wt = max(max_wt,val[n-1] + knapSack(w - wt[n-1], wt, val, n-1));
        
        return t[w][n] = max_wt;
    }
};

// Top Down
class Solution
{
    public:
    int knapSack(int W, int wt[], int val[], int N) {
        vector<vector<int>> t (W+1, vector<int> (N+1));

        for (int w = 1; w <= W; w++) {
            for (int n = 1; n <= N; n++) {
                t[w][n] = t[w][n-1];
                if (w >= wt[n-1])
                    t[w][n] = max(t[w][n], val[n-1] + t[w-wt[n-1]][n-1]);
            }
        }
        
        return t[W][N];
    }
};
