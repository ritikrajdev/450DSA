#include <iostream>
#include <unordered_map>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
vector<int> common_elements(vector<vector<int>> &mat) {
    int m = mat.size();
    int n = mat[0].size();

    unordered_map<int, int> ump;
    vector<int> res;
    res.reserve(n);

    for (int j = 0; j < n; j++)
        ump[mat[0][j]] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (ump[mat[i][j]] == i)
                ump[mat[i][j]] = i + 1;

            if (i == m - 1 && ump[mat[i][j]] == m)
                res.push_back(mat[i][j]);
        }
    }
    return res;
}
} // namespace ritik

int main() {
    vector<vector<int>> mat = {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };

    cout << ritik::common_elements(mat);
    return 0;
}
