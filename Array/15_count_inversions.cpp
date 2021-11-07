#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	int merge(vector<int>& vec, int l, int m, int r) {
		vector<int> res(r-l+1);
		int k = 0, cnt = 0;

		int i = l, j = m;
		
		while (i < m && j <= r) {
			if (vec.at(i) > vec.at(j))
				cnt += m - i, res.at(k++) = vec.at(j++);
			else
				res.at(k++) = vec.at(i++);
		}

		while (i < m)
			res.at(k++) = vec.at(i++);

		while (j <= r)
			res.at(k++) = vec.at(j++);

		for (int x = l; x <= r; x++)
			vec.at(x) = res.at(x - l);

		return cnt;
	}

	int merge_sort(vector<int>& vec, int l, int r) {
		int cnt = 0;
		if (r > l) {
			int m = (r + l) / 2;
			
			cnt += merge_sort(vec, l, m);
			cnt += merge_sort(vec, m+1, r);

			cnt += merge(vec, l, m+1, r);
		}
		return cnt;
	}

	int count_inversions(vector<int>& vec) {
		int count = 0;
		return merge_sort(vec, 0, vec.size() - 1);
	}
}

int main() {
	vector<int> vec {2, 4, 1, 3, 5};
	/* vector<int> vec {2, 3, 4, 5, 6}; */
	cout << ritik::count_inversions(vec);
	return 0;
}
