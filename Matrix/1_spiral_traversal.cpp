#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
	vector<int> spiral_traversal(vector<vector<int>>& matrix, int r, int c) {
		vector<int> result;
		result.reserve(r * c);

		int top_limit = 0, bottom_limit = r-1, right_limit = c-1, left_limit = 0;
		int i = 0, j = 0;

		while (top_limit <= bottom_limit && left_limit <= right_limit) {
			// right
			while (j < right_limit)
				result.push_back(matrix.at(i).at(j++));
			top_limit++;

			// down
			while (i < bottom_limit)
				result.push_back(matrix.at(i++).at(j));
			right_limit--;

			// left
			if (top_limit <= bottom_limit) {
				while (j > left_limit)
					result.push_back(matrix.at(i).at(j--));
				bottom_limit--;
			}

			// up
			if (left_limit <= right_limit) {
				while (i > top_limit)
					result.push_back(matrix.at(i--).at(j));
				left_limit++;
			}
		}

		 result.push_back(matrix.at(i).at(j));

		return result;
	}
}

int main() {
	int r = 4, c = 4;
	vector<vector<int>> matrix {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15,16}
	};

	cout << ritik::spiral_traversal(matrix, r, c);


	return 0;
}
