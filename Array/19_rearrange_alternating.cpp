#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	vector<int> rearrange_alternating(vector<int>& vec) {
		int i = 0, j = vec.size() - 1;

		// - - - + + +
		while (i < j) {
			if (vec.at(i) < 0) i++;
			if (vec.at(j) >= 0) j--;

			if (vec.at(i) >= 0 && vec.at(j) < 0)
				swap(vec.at(i++), vec.at(j--));
		}

		j = i & 1 ? i + 1 : i;
		i = 1;

		while (j < vec.size() && vec.at(i) < 0 && vec.at(j) > 0) {
			swap(vec.at(i), vec.at(j));
			i += 2, j += 2;
		}

		return vec;
	}
}

int main() {
	/* vector<int> vec {1, 2, 3, -4, -1, 4}; */
	vector<int> vec {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
	cout << ritik::rearrange_alternating(vec);
	return 0;
}
