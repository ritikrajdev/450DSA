#include <iostream>
#include <string>
#include <unordered_map>

#include "general.h"

using namespace std;

namespace ritik {
	bool given_string_shuffled_of_two(string &s, string &s1, string &s2) {
		if (s.size() != s1.size() + s2.size())
			return false;
		unordered_map<char, int> s_ump, s1_ump, s2_ump;
		for (char x : s)
			s_ump[x]++;
		for (char x : s1)
			s1_ump[x]++;
		for (char x : s2)
			s2_ump[x]++;

		for (auto pr : s_ump) {
			char x = pr.first;
			if (pr.second != s1_ump[x] + s2_ump[x])
				return false;
		}
		return true;
	}
} // namespace ritik

int main() {
    string s1 = "XY", s2 = "12";
    string s = "1XY2";
    cout << ritik::given_string_shuffled_of_two(s, s1, s2);
    return 0;
}
