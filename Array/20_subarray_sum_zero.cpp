#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

#include "general.h"

using namespace std;

namespace ritik {
	bool sub_array_sum_zero(vector<int>& vec) {
		unordered_map<int, int> hashmap;

		int sum = 0;
		for (const auto& elm: vec){
			sum += elm;

			if (sum == 0 || hashmap[sum])
				return true;

			hashmap[sum] = 1;
		}

		return false;

		// n^2
		/* for (int i = 0; i < vec.size(); i++) { */
		/* 	int sum = 0; */
		/* 	for (int j = i; j < vec.size(); j++) { */
		/* 		sum += vec.at(j); */
		/* 		if (sum == 0) */ 
		/* 			return true; */
		/* 	} */
		/* } */

		return false;
	}
}

int main() {
	vector<int> vec {4 ,2 ,-3 ,1 ,6};
	/* vector<int> vec {-3, 2, 3, 1, 6}; */
	cout << ritik::sub_array_sum_zero(vec);
	return 0;
}
