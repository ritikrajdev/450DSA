#include <iostream>
#include <vector>
#include <string>
#include <climits>

#include "general.h"

using namespace std;

namespace ritik {
	int max_profit(vector<int>& prices) {
		int first_buy = INT_MIN, first_sell = 0, second_buy = INT_MIN, second_sell = 0;
		for (auto& price: prices) {
			first_buy = max(first_buy, -price);
			first_sell = max(first_sell, price + first_buy);
			second_buy = max(second_buy, first_sell - price);
			second_sell = max(second_sell, price + second_buy);
		}

		return second_sell;
	}
}

int main() {
	vector<int> prices {3,3,5,0,0,3,1,4};
	cout << ritik::max_profit(prices);
	return 0;
}
