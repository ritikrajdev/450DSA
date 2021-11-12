#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "general.h"

using namespace std;

namespace ritik {
	vector<int> more_than_n_by_3(vector<int>& vec) {
		int counter1 = 0, counter2 = 0;
		int elm1, elm2;

		for (auto& elm: vec) {
			if (elm == elm1) counter1++;
			else if (elm == elm2) counter2++;
			else if (counter1 == 0) elm1 = elm, counter1++;
			else if (counter2 == 0) elm2 = elm, counter2++;
			else counter1--, counter2--;
		}

		counter1 = counter2 = 0;

		for (auto& elm: vec)
			elm == elm1 ? counter1++
				: elm == elm2 ? counter2 ++ : NULL;

		vector<int> answer;
		if (counter1 > vec.size() / 3) answer.push_back(elm1);
		if (counter2 > vec.size() / 3) answer.push_back(elm2);

		return answer;
	}
}

int main() {
	return 0;
}
