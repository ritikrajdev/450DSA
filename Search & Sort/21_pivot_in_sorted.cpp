#include <iostream>
#include <vector>
#include <limits>

using namespace std;

namespace ritik {
	int pivot(vector<int> arr) {
		int l = 0, r = arr.size()-1;
		while (l <= r) {
			int m = l + (r-l)/2;

			if (arr[0] <= arr[m])
				l = m+1;
			else
				r = m-1;
		}

		return r;
	}
}

int main() {
	vector<int> vec {6, 7, 8 ,9, 10, 11, 1, 2, 3, 4};
	cout << ritik::pivot(vec);
	return 0;
}
