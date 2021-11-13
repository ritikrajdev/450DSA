#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

#include "general.h"

using namespace std;

namespace ritik {
	int find_min_diff(vector<int> vec, int no_of_distributions) {
		int min_diff = INT_MAX;
		sort(vec.begin(), vec.end());

		for (int i = 0; i <= vec.size() - no_of_distributions; i++)
			min_diff = min(vec.at(i+no_of_distributions-1) - vec.at(i), min_diff);

		return min_diff;
	} 
}

int main() {
	vector<int> vec {3, 4, 1, 9, 56, 7, 9, 12};
	cout << ritik::find_min_diff(vec, 5);
	return 0;
}
