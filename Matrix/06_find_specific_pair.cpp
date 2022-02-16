#include <algorithm>
#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
int specific_pair(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();

    for (int j = n - 2; j >= 0; j--)
        mat[m - 1][j] = max(mat[m - 1][j], mat[m - 1][j + 1]);

    for (int i = m - 2; i >= 0; i--)
        mat[i][n - 1] = max(mat[i][n - 1], mat[i + 1][n - 1]);

    int score = 0;
    for (int i = m - 2; i >= 0; i--)
        for (int j = n - 2; j >= 0; j--) {
            // can do only two things -> ya toh X - Y m X ko maximize ya Y ko minimize
            score = max(score, mat[i + 1][j + 1] - mat[i][j]);
            mat[i][j] = max({mat[i][j], mat[i + 1][j], mat[i][j + 1]});
        }

    return score;
}
} // namespace ritik

int main() {
    vector<vector<int>> mat = {{1, 2, -1, -4, -20},
                               {-8, -3, 4, 2, 1},
                               {3, 8, 6, 1, 3},
                               {-4, -1, 1, 7, -6},
                               {0, -4, 10, -5, 1}};

    cout << ritik::specific_pair(mat);
    return 0;
}
