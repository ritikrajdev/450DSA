#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "general.h"

using namespace std;

namespace ritik {
	int min_chars_front_to_palindrome(string x) {
		string y = x;
		reverse(y.begin(), y.end());

		x = x + y;
		vector<int> lps(x.size(), 0);
		int i = 0, j = 1;
		while (j < x.size()) {
			if (x[i] == x[j])
				lps[j++] = ++i;
			else if (i > 0)
				i = lps[i-1];
			else
				j++;
		}

		return y.size() - lps.back();
	}
}

int main() {
	string s = "AACECAAAA";
	cout << ritik::min_chars_front_to_palindrome(s);
	return 0;
}
