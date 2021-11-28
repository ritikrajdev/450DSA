#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "general.h"

using namespace std;

namespace ritik {
	double median(vector<int>& vec1, vector<int>& vec2) {
		if (vec1.size() > vec2.size())
			return median(vec2, vec1);

		int nums_to_median = (vec1.size() + vec2.size() + 1) / 2;
		int start = 0, end = vec1.size();

		while (start <= end) {
			// [a, b)
			int mid = (end + start) / 2;
			int nums_left_1 = mid;
			int nums_left_2 = nums_to_median - nums_left_1;

			int l1 = nums_left_1 - 1 >= 0 ? vec1.at(nums_left_1 - 1) : INT_MIN;
			int r1 = nums_left_1 < vec1.size() ? vec1.at(nums_left_1) : INT_MAX;

			int l2 = nums_left_2 - 1 >= 0 ? vec2.at(nums_left_2 - 1) : INT_MIN;
			int r2 = nums_left_2 < vec2.size() ? vec2.at(nums_left_2) : INT_MAX;

			if (l1 <= r2 && l2 <= r1) {
				return (vec1.size() + vec2.size()) % 2 ?
					max(l1, l2) :
					(double)(max(l1, l2) + min(r1, r2)) / 2;
			}
			else if (l1 > r2) end = mid - 1;
			else start = mid + 1;
		}

		return 0;
	}
}

int main() {
	/* vector<int> vec1 {3, 7, 9, 15, 18, 21, 25}; */
	/* vector<int> vec2 {4, 6, 8, 10, 11, 18}; */

	vector<int> vec1 {23, 26, 31, 35};
	vector<int> vec2 {3, 5, 7, 9, 11, 16};

	cout << ritik::median(vec1, vec2);
	return 0;
}
