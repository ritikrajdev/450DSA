#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> t;

  public:
    int _lcs(int x, int y, string &s1, string &s2) {
        if (x == 0 || y == 0)
            return 0;

        if (t[x][y] != -1)
            return t[x][y];

        if (s1[x - 1] == s2[y - 1])
            return t[x][y] = 1 + _lcs(x - 1, y - 1, s1, s2);

        return t[x][y] = max(_lcs(x, y - 1, s1, s2), _lcs(x - 1, y, s1, s2));
    }
    // Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2) {
        t = vector<vector<int>>(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        return _lcs(x, y, s1, s2);
    }
};
