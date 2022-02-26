#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
int boyer_moore(string s, string p) {
    // Pre Processing
    unordered_map<char, int> ump;

    for (int i = 0; i < p.size(); i++)
        ump[p[i]] = p.size() - i - 1;
    ump[p.back()] = p.size();

	// Matching
    for (int i = 0; i < s.size(); i++) {
        int j = i + p.size() - 1;

        if (j >= s.size())
            return -1;

        while (j >= i && s[j] == p[j - i])
            j--;

        if (j == i - 1)
            return i;
        else {
            j = i + p.size() - 1;
            i += (ump[s[j]] ? ump[s[j]] : p.size()) - 1;
        }
    }
	return -1;
}
} // namespace ritik

int main() {
    string s = "THIS IS A TEST TEXT";
    string p = "TEST";

	cout << ritik::boyer_moore(s, p);
    return 0;
}
