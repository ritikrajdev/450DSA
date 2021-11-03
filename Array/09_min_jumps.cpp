#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	int min_num_jumps(const vector<int>& vec) {
		int jumps = 0;
		int step_limit = 1;
		int end = vec.size() - 1;

		int max_step_limit = 1;
		int i = 0;

		if (i == end)
			return jumps;

		while (step_limit --) {
			max_step_limit --;
			max_step_limit = max(max_step_limit, vec.at(i));

			if (i + vec.at(i) >= end)
				return ++jumps;

			if (step_limit == 0)
				step_limit = max_step_limit, jumps++;

			i++;
		}

		return -1;
	}
}

int main() {
	vector<int> vec {2, 3, 1 ,1 ,2 ,4 ,2 ,0 ,1 ,1};
	cout << ritik::min_num_jumps(vec);
	return 0;
}
