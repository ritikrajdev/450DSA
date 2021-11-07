#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	vector <int> commonElements (const vector<int>& vec1, const vector<int>& vec2, const vector<int>& vec3) {
		int i = 0, j = 0, k = 0;

		set<int> intersection;

		while (i < vec1.size() && j < vec2.size() && k < vec3.size()) {
			if (vec1.at(i) < vec2.at(j) || vec1.at(i) < vec3.at(k))
				i++;
			else if (vec2.at(j) < vec1.at(i) || vec2.at(j) < vec3.at(k))
				j++;
			else if (vec3.at(k) < vec1.at(i) || vec2.at(j) > vec3.at(k))
				k++;
			else
				intersection.insert(vec1.at(i++)), j++, k++;
		}

		vector<int> inter (intersection.begin(), intersection.end());
		return inter;
	}
}

int main() {
	vector<int> A = {1, 5, 10, 20, 40, 80};
	vector<int> B = {6, 7, 20, 80, 100};
	vector<int> C = {3, 4, 15, 20, 30, 70, 80, 120};

	cout << ritik::commonElements(A, B, C);

	return 0;
}
