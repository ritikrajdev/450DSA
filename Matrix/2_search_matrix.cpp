#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
	bool find(vector<vector<int>>& matrix, int target) {
		int num_rows = matrix.size(), num_cols = matrix.at(0).size();
		int i = num_rows - 1, j = 0;

		while (i >= 0 && j < num_cols) {
			if (target == matrix.at(i).at(j)) return true;
			else if (target < matrix.at(i).at(j)) i--;
			else j++;
		}

		return false;
	}
}

int main() {
	vector<vector<int>> matrix {
		{1,3,5,7},
		{10,11,16,20},
		{23,30,34,60}
	};

	cout << ritik::find(matrix, 60);
	return 0;
}
