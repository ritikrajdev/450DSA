#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "general.h"

using namespace std;

namespace ritik {
	bool is_subset (vector<int>& subset, vector<int>& vec) {
		unordered_map<int, bool> hashmap;
		for (auto& elm: vec)
			hashmap[elm] = true;

		for (auto& elm: subset)
			if (!hashmap[elm])
				return false;

		return true;
	}
}

int main() {
	vector<int> vec {11, 1, 13, 21, 3, 7}, subset {11, 3, 7, 1};
	cout << ritik::is_subset(subset, vec);
	return 0;
}
