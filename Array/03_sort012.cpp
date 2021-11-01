#include <iostream>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
	// Inplace
	void sort012(vector<short int>& vec) {
		// Single Loop
		int low = 0, mid = 0, high = vec.size() - 1;

		for (auto& elm: vec) {
			if (elm == 0)
				vec.at(low++) = 0, mid ++;
			else if (elm == 1)
				vec.at(mid) = 1, mid++;
			else
				vec.at(high--) = 2;
		}


		// Counting Two Loops Required
		/* vector<short int> hashmap(3, 0); */

		/* for (const auto& i: vec) */
		/* 	hashmap.at(i) ++; */

		/* int c = 0; */
		/* for (int i = 0; i < hashmap.size(); i++) */
		/* 	while (hashmap.at(i) --) */
		/* 		vec.at(c++) = i; */
	}
}

int main() {
	vector<short int> vec {0, 0, 1, 2, 2};
	ritik::sort012(vec);
	cout << vec;
	return 0;
}

