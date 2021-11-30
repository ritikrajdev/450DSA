#include <iostream>
#include <utility>
#include <iterator>
#include <vector>
#include <string>
#include <unordered_map>

#include "general.h"

using namespace std;

namespace ritik {
	unordered_map<char, size_t> duplicates(string& s) {
		unordered_map<char, size_t> hashmap;
		for (char c: s)
			hashmap[c] ++;

		for (auto itr = hashmap.begin(); itr != hashmap.end();) {
			if ((*itr).second == 1) itr = hashmap.erase(itr);
			else itr = next(itr);
		}

		return hashmap;
	} 
}

int main() {
	string s {"Hello"};
	auto result = ritik::duplicates(s);
	cout << vector<pair<char, size_t>> (result.begin(), result.end());
	return 0;
}
