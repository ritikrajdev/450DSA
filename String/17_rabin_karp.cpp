#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "general.h"

using namespace std;

namespace ritik {
	const int base = 10;
	long long hash(string x, int s=-1, int e=-1) {
		if (s < 0) s = 0;
		if (e < 0) e = x.length() - 1;
		
		long long h = x[s] - 'A' + 1;
		for (int i = s+1; i <= e; i++)
			h = h*base + (x[i] - 'A' + 1);
		return h;
	}

	long long rehash(long long hash, char remove, char add, long long base_power_n_minus_1) {
		return base*(hash - (remove - 'A' + 1)*base_power_n_minus_1) + (add - 'A' + 1);
	}

	int search_for(string pattern, string s) {
		const int base_power_n_minus_1 = pow(base, pattern.size() - 1);
		long long p_h = hash(pattern);
		long long h = hash(s, 0, pattern.length()-1);

		if (h == p_h) return 0;

		for (int i = pattern.length(); i < s.length(); i++) {
			h = rehash(h, s[i-pattern.length()], s[i], base_power_n_minus_1);
			if (h == p_h)
				return i;
		}
		return -1;
	}
} // namespace ritik

int main() {
	string s = "ABCCDDAEFG";
	string pattern = "CDD";
	cout << ritik::search_for(pattern, s) << '\n';
	return 0;
}
