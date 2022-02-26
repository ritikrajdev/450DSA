#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool check(vector<vector<char>> &m, int i, int j, string s, pair<int, int> direction) {
        int k = 0;
        try {
            while (k < s.size()) {
                if (s[k++] != m.at(i).at(j))
                    return false;
                i += direction.first;
                j += direction.second;
            }
            return true;
        } catch (...) {
            return false;
        }
    }

	vector<vector<int>>searchWord(vector<vector<char>>m, string s){
	    vector<vector<int>> ans;
        for (int i = 0; i < m.size(); i++) {
            for (int j = 0; j < m[i].size(); j++) {
                if (m[i][j] == s[0]) {
                    bool c = check(m, i, j, s, {-1, 0}) || check(m, i, j, s, {1, 0}) ||
                         check(m, i, j, s, {0, -1}) || check(m, i, j, s, {0, 1}) ||
                         check(m, i, j, s, {-1, 1}) || check(m, i, j, s, {1, 1}) ||
                         check(m, i, j, s, {-1, -1}) || check(m, i, j, s, {1, -1});
                    if (c)
                        ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
