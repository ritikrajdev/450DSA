#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	int max(vector<int>& vec) {
		int max = -1;

		for (auto& elm: vec)
			if (elm > max)
				max = elm;

		return max;
	}

	int longest_consecutive_subarray(vector<int>& vec) {
		vector<bool> hashmap(max(vec) + 1, false);

		for (auto& elm: vec)
			hashmap[elm] = true;

		int i = 0, len = 0, max_len = -1;
		while (i < hashmap.size()) {
			while (i < hashmap.size() && hashmap.at(i))
				i++, len++;

			if (len > max_len)
				max_len = len;

			while (i < hashmap.size() && (!hashmap.at(i)))
				len = 0, i++;
		}

		return max_len;
	}
}

int main() {
	vector<int> vec {9};
	cout << ritik::longest_consecutive_subarray(vec);
	return 0;
}
