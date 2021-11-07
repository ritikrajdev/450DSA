#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	int count_inversions(vector<int>& vec) {
		// Naive n^2
		int count = 0;
		for (int i = 0; i < vec.size(); i++) {
			for (int j = i+1; j < vec.size(); j++) {
				if (vec.at(j) < vec.at(i))
					count++;
			}
		}
		return count;
	}
}

int main() {
	vector<int> vec {2, 4, 1, 3, 5};
	/* vector<int> vec {2, 3, 4, 5, 6}; */
	cout << ritik::count_inversions(vec);
	return 0;
}
