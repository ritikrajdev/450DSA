#include <cctype>
#include <iostream>
#include <string>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
	const vector<string> keypad{
		"2", "22", "222",
		"3", "33", "333",
		"4", "44", "444",
		"5", "55", "555",
		"6", "66", "666",
		"7", "77", "777", "7777",
		"8", "88", "888",
		"9", "99", "999", "9999"
	};

	string sentence_to_keypad(string &s) {
		string result;

		for (char x : s) {
			if (x == ' ')
				result += '0';
			else {
				x = tolower(x);
				result += keypad[x - 'a'];
			}
		}

		return result;
	}
} // namespace ritik

int main() {
    string s = "HELLO WORLD";
    cout << (ritik::sentence_to_keypad(s) == "4433555555666096667775553");
    return 0;
}
