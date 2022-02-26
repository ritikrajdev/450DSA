#include <iostream>
#include <string>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
bool check_up(vector<vector<char>> &m, int i, int j, string s) {
    if (i + 1 < s.size())
        return 0;
    int k = 0;
    while (k < s.size())
        if (s[k++] != m[i--][j])
            return false;
    return true;
}

bool check_down(vector<vector<char>> &m, int i, int j, string s) {
    if (m.size() - i < s.size())
        return 0;
    int k = 0;
    while (k < s.size())
        if (s[k++] != m[i++][j])
            return false;
    return true;
}

bool check_right(vector<vector<char>> &m, int i, int j, string s) {
    if (m[i].size() - j < s.size())
        return 0;
    int k = 0;
    while (k < s.size())
        if (s[k++] != m[i][j++])
            return false;
    return true;
}

bool check_left(vector<vector<char>> &m, int i, int j, string s) {
    if (j + 1 < s.size())
        return 0;
    int k = 0;
    while (k < s.size())
        if (s[k++] != m[i][j--])
            return false;
    return true;
}

int count_in_2d(vector<vector<char>> &m, string s) {
    int c = 0;
    for (int i = 0; i < m.size(); i++) {
        for (int j = 0; j < m[i].size(); j++) {
            if (m[i][j] == s[0]) {
                c += check_up(m, i, j, s) + check_down(m, i, j, s) +
                     check_left(m, i, j, s) + check_right(m, i, j, s);
            }
        }
    }
    return c;
}
} // namespace ritik

int main() {
    vector<vector<char>> m = {
        {'D', 'D', 'D', 'G', 'D', 'D'},
		{'B', 'B', 'D', 'E', 'B', 'S'},
        {'B', 'S', 'K', 'E', 'B', 'K'},
		{'D', 'D', 'D', 'K', 'D', 'E'},
        {'D', 'D', 'D', 'S', 'D', 'E'},
		{'X', 'S', 'K', 'E', 'E', 'G'}};
	
	cout << ritik::count_in_2d(m, "GEEKS");

    return 0;
}
