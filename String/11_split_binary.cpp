#include <iostream>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
int split_binary_string(string s) {
    if (s.length() % 2)
        return -1;

    int count = 0;
    int counts[2] = {0, 0};

    for (auto x : s) {
        counts[x - '0']++;
        if (counts[0] == counts[1])
            count++;
    }

    if (counts[0] != counts[1])
        return -1;
    return count;
}
} // namespace ritik

int main() {
    cout << ritik::split_binary_string("0100110101");
    cout << ritik::split_binary_string("0111100010");
    cout << ritik::split_binary_string("00");
    return 0;
}
