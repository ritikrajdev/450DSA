#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <numeric>

#include "general.h"

using namespace std;

namespace ritik {
	int min_subarray_len(vector<int>& vec, int x) {
		if (accumulate(vec.begin(), vec.end(), 0) < x)
			return 0;
		
		int min_len = INT_MAX;

		int i = 0, j = 0;
		long long sum_i_j = 0;

		while (j < vec.size()) {
			while (sum_i_j < x && j < vec.size())
				sum_i_j += vec.at(j++);

			while (x <= sum_i_j && i < j)
				sum_i_j -= vec.at(i++);

			cout << i << ' ' << j << endl;

			min_len = min(min_len, j - i + 1);
		}

		return min_len;
	}
}

int main() {
	vector<int> vec {2,3,1,2,4,3};
	cout << ritik::min_subarray_len(vec, 7);

	return 0;
}
