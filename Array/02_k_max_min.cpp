#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>
#include <set>

#include "general.h"

using namespace std;

namespace ritik {
	template <typename comparable>
	pair<comparable, comparable> k_max_min(const vector<comparable>& vec, int k_min, int k_max) {
		if (vec.size() == 0)
			throw invalid_argument("Vector Size is 0");
		if (k_min < 0 || k_max < 0)
			throw invalid_argument("k can't be negative");

		comparable min, max;

		// K Min, Max
		set<comparable> st;
		for (auto elm: vec)
			st.insert(elm);

		// Can be made to advance in a single loop but m lazy
		min = *next(st.begin(), k_min);
		max = *next(st.rbegin(), k_max);

		return {min, max};
	}


}

int main() {
	vector<int> vec {12, 3, 5, 7, 19};
	cout << ritik::k_max_min(vec, 3, 3) << '\n';
	return 0;
}

