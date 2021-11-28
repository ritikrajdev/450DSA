#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "general.h"

using namespace std;

namespace ritik {
	int minimize_max_height(vector<int>& vec, int k) {
		sort(vec.begin(), vec.end());

		int min_height = vec.back() - vec.front();

		if (vec.back() - k <= 0)
			return min_height;

		for (int i = 0; i < vec.size() - 1; i++) {
			int max_from_pair = max(vec.back() - k, vec.at(i) + k);
			int min_from_pair = min(vec.front() + k, vec.at(i+1) - k);

			if (min_from_pair < 0) continue;

			min_height = min(min_height, max_from_pair - min_from_pair);
		}

		return min_height;
	}
}

int main() {
	vector<int> vec {3, 9, 12, 16, 20};
	cout << ritik::minimize_max_height(vec, 3);
	return 0;
}
