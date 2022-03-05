#include <bits/stdc++.h>
using namespace std;

bool meets_requirement(int guessed_height, int requirement,
                       vector<int> &height) {
    int sm = 0;
    for (int i = 0; i < height.size(); i++)
        sm += max(0, height[i] - guessed_height);
    return sm >= requirement;
}

int max_height(int n, int m, vector<int> &height) {
    int ans = -1;
    sort(height.begin(), height.end());

    int l = 0, h = height.back();
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (meets_requirement(mid, m, height)) {
            ans = mid;
            l = mid + 1;
        } else
            h = mid - 1;
    }
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> height(n);
    for (auto &h : height)
        cin >> h;

    cout << max_height(n, m, height);

    return 0;
}
