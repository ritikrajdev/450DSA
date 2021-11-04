#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
		if (intervals.empty()) return {{}};
		vector<vector<int>> result;

		sort(intervals.begin(), intervals.end(), [&](vector<int>& x, vector<int>& y) {return x[0] < y[0];});
		result.push_back(intervals.at(0));
		for (auto interval: intervals) {
			if (interval[0] <= result.back()[1])
				result.back()[1] = max(interval[1], result.back()[1]);
			else
				result.push_back(interval);
		}

		return result;
    }
}

int main() {
	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};
	/* vector<vector<int>> intervals = {{1,4},{4,5}}; */
	/* vector<vector<int>> intervals = {{1,4},{0,5}}; */

	cout << ritik::merge_intervals(intervals);
	return 0;
}
