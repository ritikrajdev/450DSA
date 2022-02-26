#include <string>
#include <vector>
#define ll long long int
using namespace std;

class Solution {
    string s;
    vector<vector<ll>> t;

  public:
    ll cntPS(int i, int j) {
        if (j < i)
            return 0;

        if (t[i][j] != -1)
            return t[i][j];

        if (j == i)
            return t[i][j] = 1;

        if (s[i] == s[j])
            return t[i][j] = cntPS(i + 1, j) + cntPS(i, j - 1) + 1;

        return t[i][j] =
                   cntPS(i + 1, j) + cntPS(i, j - 1) - cntPS(i + 1, j - 1);
    }

    ll countPS(string str) {
        t = vector<vector<ll>>(str.size() + 1, vector<ll>(str.size() + 1, -1));
        s = str;

        return cntPS(0, str.size() - 1);
    }
};
