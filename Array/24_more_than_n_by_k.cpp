#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "general.h"

using namespace std;

namespace ritik {
	vector<int> more_than_n_by_k(const vector<int>& vec, int k = 3) {
		vector<int> answer;
		unordered_map<int, int> hashmap;

		for (auto& elm: vec) hashmap[elm]++;

		for (auto& pair: hashmap)
			if (pair.second > vec.size()/k)
				answer.push_back(pair.first);

		// Can Prefer Space over time by using sort, but it time is more valuable than space

		return answer;
	}
}

int main() {
	vector<int> vec {3,2,3};
	cout << ritik::more_than_n_by_k(vec);
	return 0;
}
