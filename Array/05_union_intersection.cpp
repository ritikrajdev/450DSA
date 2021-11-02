#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {

	void _helper(vector<int>& vec, int val) {
		if (vec.size() == 0)
			vec.push_back(val);

		if (vec.back() != val)
			vec.push_back(val);
	}

	// m + n
	vector<int> union_vec(const vector<int>& vec1, const vector<int>& vec2) {
		vector<int> _union;
		int i = 0, j = 0;

		while (i < vec1.size() && j < vec2.size()) {
			_helper(_union, 
					vec1.at(i) < vec2.at(j) ? vec1.at(i++) : vec2.at(j++));
		}

		while (i < vec1.size()) {
			_helper(_union, vec1.at(i++));
		}

		while (j < vec2.size()) {
			_helper(_union, vec2.at(j++));
		}

		return _union;
	}


	// n Log(m)  considering n <= m
	vector<int> intersection_vec(const vector<int>& vec1, const vector<int>& vec2) {
		const vector<int>& longer = vec1.size() > vec2.size() ? vec1 : vec2;
		const vector<int>& shorter = vec1.size() <= vec2.size() ? vec1 : vec2;

		vector<int> _intersection;
		for (auto elm: shorter) {
			if (binary_search(longer.begin(), longer.end(), elm))
				_helper(_intersection, elm);
		}

		return _intersection;
	}
}

int main() {
	vector<int> vec1 {1, 2, 3, 4, 5, 5, 6};
	vector<int> vec2 {3, 4, 4, 5, 7};

	cout << ritik::union_vec(vec1, vec2) << '\n';
	cout << ritik::intersection_vec(vec1, vec2) << '\n';
	return 0;
}
