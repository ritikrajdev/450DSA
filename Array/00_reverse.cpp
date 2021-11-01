#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	template <typename T>
	T reverse(const T& arr) {
		T result {arr};
		
		// Reverse
		for (int i = 0, j = result.size() - 1; i < j; i++, j--)
			swap(result.at(i), result.at(j));

		return result;
	}
}

int main() {
	vector<int> vec {1,2,3,4};
	cout << ritik::reverse(vec) << '\n';

	string str {"Hello"};
	cout << ritik::reverse(str);
	return 0;
}

