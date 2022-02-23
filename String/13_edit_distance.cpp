#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> memory;

    int solve(string &s, string &t, int n1, int n2) {
        if (n1 == 0)
            return n2; // insert all characters left

        if (n2 == 0)
            return n1; // delete all characters left

        if (memory[n1][n2] != -1)
            return memory[n1][n2];

        if (s[n1 - 1] == t[n2 - 1])
            return memory[n1][n2] = solve(s, t, n1 - 1, n2 - 1);
        else
            return memory[n1][n2] = min({
                       solve(s, t, n1 - 1, n2) + 1,     // Deletion
                       solve(s, t, n1 - 1, n2 - 1) + 1, // Edit
                       solve(s, t, n1, n2 - 1) + 1      // Insert
                   });
    }

  public:
    int editDistance(string s, string t) {
        memory =
            vector<vector<int>>(s.size() + 1, vector<int>(t.size() + 1, -1));
        return solve(s, t, s.size(), t.size());
    }
};
