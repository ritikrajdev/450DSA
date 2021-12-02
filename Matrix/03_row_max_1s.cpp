#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
	size_t row_with_max_1s(vector<vector<int>> vec, int n, int m) {
		int row_max_1s = 0;
		int i = 0, j = m-1;

		while (i < n) {
			if (j == -1)
				return i;

			if (vec.at(i).at(j) == 0) i++;
			else {
				while (j >= 0 && vec.at(i).at(j) != 0) j--;
				row_max_1s = i;
			}
		}

		if (vec.at(row_max_1s).at(m-1) == 0) return -1;

		return row_max_1s;
	}
}

int main() {
	vector<vector<int>> x = {{0, 0, 1, 1, 1},
							 {0, 0, 0, 1, 1}, 
							 {0, 1, 1, 1, 1}, 
							 {0, 0, 0, 0, 0}};

	cout << ritik::row_with_max_1s(x, x.size(), x.at(0).size());

	return 0;
}
