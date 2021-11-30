#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
    void reverse_string(vector<char>& s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++)
            swap(s.at(i), s.at(n - i - 1));
    }
};

int main() {
	vector<char> s {'h','e','l','l','o'};
	ritik::reverse_string(s);
	cout << s;
	return 0;
}

