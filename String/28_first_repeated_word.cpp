#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
string first_repeated_word(string &s) {
    unordered_map<string, bool> ump;
    string word = "";
    for (auto x : s) {
        if (x == ' ') {
            if (ump[word])
                return word;
            else {
                ump[word] = 1;
				word = "";
			}
        } else
            word.push_back(x);
    }

    if (ump[word])
        return word;
    else
        return "";
}
} // namespace ritik

int main() {
    string u = "Ravi had been saying that he had been there";
    string v = "Ravi had been saying that";
    string w = "he had had he";
    cout << ritik::first_repeated_word(u) << '\n';
    cout << ritik::first_repeated_word(v) << '\n';
    cout << ritik::first_repeated_word(w) << '\n';

    return 0;
}
