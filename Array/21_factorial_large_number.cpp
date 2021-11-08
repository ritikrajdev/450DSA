#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "general.h"

using namespace std;

namespace ritik {
	void _multiply(int multiplier, vector<int>& multiplicand) {
		int carry = 0;

		for (int i = 0; i < multiplicand.size(); i++) {
			int product = multiplier * multiplicand.at(i) + carry;
			carry = product / 10;
			multiplicand.at(i) = product % 10;
		}

		while (carry > 0) {
			multiplicand.push_back(carry % 10);
			carry = carry / 10;
		}
	}

	vector<int> factorial(int n) {
		vector<int> product {1};
		for (int i = 2; i <= n; i++) {
			_multiply(i, product);
		}

		reverse(product.begin(), product.end());
		return product;
	}
}

int main() {
	int n = 6;
	cout << ritik::factorial(6);
	return 0;
}
