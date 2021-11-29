#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
	bool find(vector<vector<int>>& matrix, int target) {
		// O (log(m*n))
		int num_rows = matrix.size(), num_cols = matrix.at(0).size();
		int l = 0, h = (num_rows * num_cols) - 1;

		while (l <= h) {
			int m = (l + h) / 2;
			
			int value = matrix.at(m / num_cols).at(m % num_cols);
			if (target == value) return true;
			else if (target < value) h = m - 1;
			else l = m + 1;
		}

		return false;


		// O(m + n)
		/* int num_rows = matrix.size(), num_cols = matrix.at(0).size(); */
		/* int i = num_rows - 1, j = 0; */

		/* while (i >= 0 && j < num_cols) { */
		/* 	if (target == matrix.at(i).at(j)) return true; */
		/* 	else if (target < matrix.at(i).at(j)) i--; */
		/* 	else j++; */
		/* } */

		/* return false; */
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
