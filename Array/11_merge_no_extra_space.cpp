#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "general.h"

using namespace std;

namespace ritik {
	void merge(vector<int>& vec1, vector<int>& vec2) {
		// Let's try to do it in (m+n)


		// easy to think (mlog(n))
		int i = 0, j = 0, k = vec1.size() - 1;

		while (i < vec1.size() && j < vec2.size()) {
			if (vec1.at(i) < vec2.at(j)) i++;
			else swap(vec1.at(k--), vec2.at(j++));
		}

		sort(vec1.begin(), vec1.end());
		sort(vec2.begin(), vec2.end());


		// Naive But Easy to Understand (mn)
		/* int i = 0, j = 0, k = 0; */
		/* for (auto& elm: vec1) { */
		/* 	if (elm > vec2.at(0)) { */
		/* 		swap(vec2.at(0), elm); */
		/* 		int k = 1; */
		/* 		while (vec2.at(k) < vec2.at(k-1) && k < vec2.size()) { */
		/* 			swap(vec2.at(k-1), vec2.at(k)); */
		/* 			k++; */
		/* 		} */
		/* 	} */
		/* } */
	}
}

int main() {

	vector<int> vec1 {1 ,3 ,5 ,7}; 
	vector<int> vec2 {0 ,2 ,6 ,8 ,9};

	ritik::merge(vec1, vec2);

	cout << vec1 << vec2;
	return 0;
}
