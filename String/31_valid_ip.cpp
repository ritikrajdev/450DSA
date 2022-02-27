#include <iostream>
#include <string>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
bool valid(string x) {
    if (x.size() > 3)
        return false;
    if (x[0] == '0' && x.size() > 1)
        return false;
    if (stoi(x) > 255)
        return false;
    return true;
}

vector<string> valid_ips(string s) {
    // Selecting position of dots
    // 192168181
    // Assuming x means . before x index
	
	if (s.length() > 12)
		return {};

    vector<string> result;
    for (int i = 1; i < s.size() - 2; i++) {
        if (!valid(s.substr(0, i))) continue;
        for (int j = i + 1; j < s.size() - 1; j++) {
            if (!valid(s.substr(i, j - i))) continue;
            for (int k = j + 1; k < s.size(); k++) {
                if (!valid(s.substr(j, k - j))) continue;
                if (!valid(s.substr(k))) continue;

                result.push_back(s.substr(0, i) + "." + s.substr(i, j - i) +
                                 "." + s.substr(j, k - j) + "." + s.substr(k));
            }
        }
    }

    return result;
}
} // namespace ritik

int main() {
    cout << ritik::valid_ips("192168181") << '\n';
	cout << ritik::valid_ips("25505011535") << '\n';
	cout << ritik::valid_ips("25525511135") << '\n';
    return 0;
}
