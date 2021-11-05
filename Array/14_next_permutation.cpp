#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "general.h"

using namespace std;

namespace ritik {
	void next_permutation (vector<int>& vec) {
		int in1 = -1;

		for (int i = vec.size() - 2; i >= 0; i--) {
			if (vec.at(i) < vec.at(i+1)) {
				in1 = i;
				break;
			}
		}

		if (in1 >= 0) {
			for (int i = vec.size() - 1; i >= in1; i--) {
				if (vec.at(i) > vec.at(in1)) {
					swap(vec.at(i), vec.at(in1));
					break;
				}
			}
		}

		reverse(vec.begin() + in1 + 1, vec.end());
	}
}

int main() {
	vector<int> vec {1,2,3};
	ritik::next_permutation(vec);
	cout << vec;
}

