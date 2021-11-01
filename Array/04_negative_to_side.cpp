#include <cstddef>
#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
	void negative_to_side(vector<int>& vec) {

		// Two Pointer, Lesser Avg. case time
		for (int i = 0, j = vec.size() - 1; i < j;) {
			int& left = vec.at(i);
			int& right = vec.at(j);

			if (left >= 0 && right < 0)
				swap(left, right), i++, j--;
			
			else {
				if (left < 0) i++;
				if (right >= 0)  j--;
			}
		}


		// Partition Approach (Exactly Loops over array) => O(n)
		/* size_t x = 0; */
		/* for (auto& elm:vec) */
		/* 	if (elm < 0) */
		/* 		swap(elm, vec.at(x++)); */
	}
}

int main() {
	vector<int> vec {-12, 11, -13, -5, 6, -7, 5, -3, -6};
	ritik::negative_to_side(vec);
	cout << vec;
	return 0;
}
