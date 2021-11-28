#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "general.h"

using namespace std;

namespace ritik {
	
	// Assumption: All Elements are Positive
	int min_operations_array_palindrome (vector<int>& vec) {
		int i = 0, sum_i = vec.at(i), j = vec.size() - 1, sum_j = vec.at(j);
		int merge_nums = 0;

		while (i < j) {
			if (sum_i == sum_j)
				i++, j--, sum_i = vec.at(i), sum_j = vec.at(j);
			else if (sum_i < sum_j)
				merge_nums++, i++, sum_i += vec.at(i); 
			else 
				merge_nums++, j--, sum_j += vec.at(j);
		}

		return merge_nums;
	}
}

int main() {
	vector<int> vec {10, 99, 44, 10};
	cout << ritik::min_operations_array_palindrome(vec);
	return 0;
}
