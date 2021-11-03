#include <cmath>
#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	int find_duplicate(vector<int>& vec) {
		int curr;

		for (auto& elm: vec) {
			curr = abs(elm);
			if (vec.at(curr) > 0)
				vec.at(curr) = -vec.at(curr);
			else
				break;
		}

		for (auto& elm: vec)
			elm = abs(elm);

		return curr;
	}
}

int main() {
	vector<int> vec {3,1,3,4,2};
	cout << ritik::find_duplicate(vec);
	return 0;
}
