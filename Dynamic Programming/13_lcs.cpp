class Solution
{
    vector<vector<int>> t;
    public:
    Solution() {
        t = vector<vector<int>> (1002, vector<int>(1002, -1));
    }
    int lcs(int x, int y, string s1, string s2)
    {
        if (x == 0 || y == 0)
            return 0;
        
        if (t[x][y] != -1) return t[x][y];

        int c1 = lcs(x-1, y-1, s1, s2);
        if (s1[x-1] == s2[y-1])
            c1++;
        
        return t[x][y] = max({
            c1,
            lcs(x-1, y, s1, s2),
            lcs(x, y-1, s1, s2),
        });
    }
};
