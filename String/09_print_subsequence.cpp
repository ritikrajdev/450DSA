#include <iostream>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
void print_subsequence(string &s, string decisor = "") {
    if (decisor.length() == s.length()) {
        for (int i = 0; i < s.length(); i++)
            if (decisor[i] - '0')
                cout << s[i];
        cout << '\n';
        return;
    }

    print_subsequence(s, decisor + "1");
    print_subsequence(s, decisor + "0");
}
} // namespace ritik

int main() {
    string input = "abcd";
    ritik::print_subsequence(input);
    return 0;
}
