#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "general.h"

using namespace std;

namespace ritik {
	int count_pairs_given_sum(const vector<int>& vec, int sum) {
		unordered_map<int, int> hashmap;
		unsigned int cnt = 0;

		for (auto elm: vec)
			hashmap[elm]++;

		for (auto elm: vec) {
			if (hashmap[sum - elm]) {
				cnt += hashmap[sum - elm];

				if (sum - elm == elm)
					cnt --;
			}
		}

		return cnt / 2;
    }
}

int main() {
	vector<int> vec {1, 1, 1, 1};
	cout << ritik::count_pairs_given_sum(vec, 2);
	return 0;
}

