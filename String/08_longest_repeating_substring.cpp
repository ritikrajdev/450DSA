#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> t;
    int lcs(string &s1, string &s2, int n1, int n2) {
        if (n1 == 0 || n2 == 0)
            return t[n1][n2] = 0;

        if (t[n1][n2] != -1)
            return t[n1][n2];

        if (s1[n1 - 1] == s2[n2 - 1] && n1 != n2)
            return t[n1][n2] = lcs(s1, s2, n1 - 1, n2 - 1) + 1;
        return t[n1][n2] =
                   max(lcs(s1, s2, n1 - 1, n2), lcs(s1, s2, n1, n2 - 1));
    }

  public:
    int LongestRepeatingSubsequence(string str) {
        t = vector<vector<int>>(str.length() + 1,
                                vector<int>(str.length() + 1, -1));
        return lcs(str, str, str.length(), str.length());
    }
};
