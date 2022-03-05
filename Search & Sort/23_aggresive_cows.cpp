#include <bits/stdc++.h>
using namespace std;

bool canArrange(int c, vector<int> &position, int min_difference) {
    if (position.size() == 0)
        return 0;

    if (c == 1 && position.size())
        return true;

    int last_placed = position[0];
    c--;

    for (int i = 1; i < position.size(); i++) {
        if (position[i] - last_placed >= min_difference) {
            last_placed = position[i];
            c--;

            if (c == 0)
                return true;
        }
    }

    return false;
}

int solve() {
    int n, c;
    cin >> n >> c;
    vector<int> position(n);
    for (int i = 0; i < n; i++)
        cin >> position[i];

    sort(position.begin(), position.end());

    int ans = -1;
    int l = 1, h = position.back() - position.front();
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (canArrange(c, position, m))
            ans = m, l = m + 1;
        else
            h = m - 1;
    }

	return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
    return 0;
}
