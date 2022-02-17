#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
unordered_map<char, size_t> counter(string s) {
    unordered_map<char, size_t> ump;

    for (char x : s)
        ump[x]++;

    return ump;
}

int min_operations(string &s1, string &s2) {
    if (counter(s1) != counter(s2))
        return -1;

    int i = s1.size() - 1, j = s2.size() - 1;
    int c = 0;

    while (i >= 0 && j >= 0) {
        if (s1[i] == s2[j]) j--;
        else c++;

		i--;
    }

    return c;
}
} // namespace ritik

int main() {
    /* string s1 = "EACBD", s2 = "EABCD"; */
    string s1 = "ABC", s2 = "BAC";
    cout << ritik::min_operations(s1, s2);
    return 0;
}
