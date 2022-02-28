#include<bits/stdc++.h>

using namespace std;

int last_index(vector<int> arr, int x) {
	int i = 0, j = arr.size() - 1;

	int ans = -1;

	while (i <= j) {
		int m = i + (j - i)/2;
		if (arr[m] <= x)
			ans = m, i = m + 1;
		else
			j = m - 1;
	}
	return ans;
}

int main() {

	int n, q;
	cin >> n;
	vector<int> powers(n);
	for (auto& p: powers)
		cin >> p;
	
	sort(powers.begin(), powers.end());
	
	vector<int> sums(n);
	sums[0] = powers[0];
	for (int i = 1; i < n; i++)
		sums[i] = sums[i-1] + powers[i];
	
	cin >> q;
	while (q--) {
		int p;
		cin >> p;

		int a_num, a_sum;
		if (p >= powers.back())
			a_num = powers.size(), a_sum = sums.back();
		else if (p < powers[0])
			a_num = 0, a_sum = 0;
		else {
			int x = last_index(powers, p);
			a_num = x+1, a_sum = sums[x];
		}
		cout << a_num << ' ' << a_sum << '\n';
	}

	return 0;
}
