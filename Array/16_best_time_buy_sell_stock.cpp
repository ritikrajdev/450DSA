#include <iostream>
#include <vector>
#include <string>

#include "general.h"

using namespace std;

namespace ritik {
	int max_profit(const vector<int>& prices) {
		int min_price_so_far = prices.at(0);
		int profit = 0;

		for (auto price: prices) {
			profit = max(price - min_price_so_far, profit);
			min_price_so_far = min(price, min_price_so_far);
		}

		return profit;
    }
}

int main() {
	vector<int> vec {7,1,5,3,6,4};
	cout << ritik::max_profit(vec);
	return 0;
}
