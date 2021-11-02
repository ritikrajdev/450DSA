#include <iostream>
#include <vector>
#include <string>
#include <numeric>

#include "general.h"

using namespace std;

namespace ritik {
	int largest_sum_subarray(const vector<int>& vec) {
		int max_so_far = vec.at(0), max = vec.at(0);

		int mean = accumulate(vec.begin(), vec.end(), 0) / vec.size();

		for (int i = 1; i < vec.size(); i++) {
			max_so_far += vec.at(i);

			if (max_so_far > max)
				max = max_so_far;
			
			else if (max_so_far < mean)
				max_so_far = 0;
		}

		return max >= 0 ? max : -1;
	}
}

int main() {
	vector<int> vec {1,2,3,-2,5};
	/* vector<int> vec {-5,-2,2,-1,6}; */
	/* vector<int> vec {-5,-2,-3}; */
	cout << ritik::largest_sum_subarray(vec);

	return 0;
}
