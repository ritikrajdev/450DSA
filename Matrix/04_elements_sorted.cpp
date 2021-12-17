#include <algorithm>
#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
void print_sorted_matrix(const vector<vector<int>> &Mat) {
	// Size N^2, Time N^2 Log(N)
    vector<int> vec;
    vec.reserve(Mat.size() * Mat.at(0).size());
    for (auto row : Mat)
        for (auto elm : row)
            vec.push_back(elm);
    sort(vec.begin(), vec.end());

    cout << vec;
}
} // namespace ritik

int main() {
    vector<vector<int>> matrix = {
        {10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
	ritik::print_sorted_matrix(matrix);
    return 0;
}
