#include <iostream>
#include <climits>
#include <vector>

using namespace std;

namespace ritik {
	pair<int, int> min_max(vector<int> v) {
		int n = v.size();
		int min = INT_MAX, max = INT_MIN, i = 0;

		if (n % 2)
			min = max = v[0], i = 1;
		else
			i = 0;

		while (i < n) {
			if (v[i] < v[i+1]) {
				if (v[i+1] > max) max = v[i+1];
				if (v[i] < min) min = v[i];
			} else {
				if (v[i] > max) max = v[i];
				if (v[i+1] < min) min = v[i+1];
			}
			i += 2;
		}

		return {min, max};
	}
}

int main() {
	vector<int> v {1,2,3,4,5,6,7,8,9};
	auto result = ritik::min_max(v);
	cout << result.first << ' ' << result.second << '\n';

	v.push_back(10);
	result = ritik::min_max(v);
	cout << result.first << ' ' << result.second << '\n';
	return 0;
}
