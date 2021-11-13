#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "general.h"

using namespace std;

namespace ritik {
	int min_swap(vector<int>& vec, int k) {
		int window_size = 0;
		for (auto& elm: vec)
			if (elm <= k)
				window_size++;

		if (window_size == 0) return 0;

		int swaps = 0, min_swap = INT_MAX;
		for (int i = 0; i < window_size; i++)
			if (vec[i] > k)
				swaps++;

		min_swap = swaps;

		for (int i = window_size; i < vec.size(); i++) {
			if (vec[i-window_size] <= k && vec[i] > k) swaps++;
			if (vec[i-window_size] > k && vec[i] <= k) swaps--;

			min_swap = min(min_swap, swaps);
		}

		return min_swap;
	}
}

int main() {
	vector<int> vec {2, 7, 9, 5, 8, 7, 4};
	cout << ritik::min_swap(vec, 6);
	return 0;
}
