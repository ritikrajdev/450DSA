#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>

#include "general.h"

using namespace std;

namespace ritik {
	template <typename comparable>
	pair<comparable, comparable> min_max(vector<comparable> vec) {
		if (vec.size() == 0)
			throw invalid_argument("Vector Size is 0");

		comparable min, max;
		min = max = vec.at(0);
		
		for (auto elm: vec) {
			if (elm > max) max = elm;
			else if (elm < min) min = elm;
		}

		return {min, max};
	}
}

int main() {
	vector<int> vec {1, 2, 3, 4, 5};
	cout << ritik::min_max(vec);
	return 0;
}

