#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	template <typename T>
	vector<T> rotate_by_1(const vector<T>& vec) {
		vector<T> result {vec};
		
		for (int i = result.size() - 1; i > 0; i--)
			swap(result.at(i), result.at(i-1));

		return result;
	}
}

int main() {
	vector<int> vec {1, 2, 3, 4, 5};
	
	cout << ritik::rotate_by_1(vec);
	return 0;
}
