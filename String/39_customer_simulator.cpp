#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

#include "general.h"

using namespace std;

namespace ritik {
int runCustomerSimulation(int n, string s) {
    int maxN = n;
    unordered_map<char, bool> present, waiting;
    int c = 0;

    for (auto x : s) {
        if (present[x]) {
            n++;
			present[x] = false;
            present.erase(x);
            if (waiting.size()) {
                char c = waiting.begin()->first;
                present[c] = true;
                n--;
				waiting[c] = false;
                waiting.erase(c);
            }
        } else if (n > 0) {
            n--, present[x] = true;
        } else if (waiting[x]) {
            c++;
            waiting.erase(x);
        } else {
			waiting[x] = true;
		}
    }

    return c;
}
} // namespace ritik

int main() {
    cout << ritik::runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << ritik::runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << ritik::runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << ritik::runCustomerSimulation(1, "ABCBCA") << endl;
    cout << ritik::runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}
