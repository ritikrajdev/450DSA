#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <functional>

#include "general.h"

using namespace std;

namespace ritik {
	int max(vector<int>& vec) {
		int maxi = INT_MIN;
		for (auto& elm: vec)
			maxi = std::max(elm, maxi);
		return maxi;
	}

	template<typename T>
	T max(T a, T b, T c) {
		if (a >= b  && a >= c) return a;
		if (b >= a && b >= c) return b;
		if (c >= a && c >= b) return c;
	}

	template<typename T>
	T min(T a, T b, T c) {
		if (a <= b  && a <= c) return a;
		if (b <= a && b <= c) return b;
		if (c <= a && c <= b) return c;
	}

	int max_product_subarray(vector<int>& vec) {
		long long absolute_max_product = max(vec);
		long long max_product = 1, min_product = 1;

		for (auto& elm: vec) {
			if (elm == 0)
				max_product = min_product = 1;
			else {
				long long tmp = max_product;
				max_product = max(elm * max_product, elm * min_product, (long long)elm);
				min_product = min(elm * tmp, elm * min_product, (long long)elm);
			}

			absolute_max_product = std::max(absolute_max_product, max_product);
		}

		return absolute_max_product;
	}
}

int main() {
	vector<int> vec {6, -3, -10, 0};
	cout << ritik::max_product_subarray(vec);
	return 0;
}
