#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "general.h"

using namespace std;

namespace ritik {
	int trapping_water(vector<int>& heights) {
		vector<int> left, right (heights.size());
		left.reserve(heights.size());

		int maxi = INT_MIN;
		for (auto elm: heights)
			left.push_back(maxi = elm > maxi ? elm : maxi);

		maxi = INT_MIN;
		for (int i = heights.size() - 1; i >= 0; i--)
			right.at(i) = maxi = heights.at(i) > maxi ? heights.at(i) : maxi;

		int volume = 0;
		for (int i = 0; i < heights.size(); i++)
			volume += min(right.at(i), left.at(i)) - heights.at(i);
		
		return volume;
	}
}

int main() {
	vector<int> heights {3,0,0,2,0,4};
	cout << ritik::trapping_water(heights);
	return 0;
}
