#include <iostream>
#include <unordered_map>
using namespace std;

// Could've used Majority element to do this
void solve() {
    string s;
    cin >> s;
    unordered_map<char, size_t> ump;
    int n = s.length();
    bool ans = false;
    for (auto c : s)
        ump[c]++;

    char c = s[0];
    for (auto pr : ump)
        if (pr.second > ump[c])
            c = pr.first;

    if (ump[c] > (n + 1) / 2)
        ans = false;
    else
        ans = true;

    cout << ans << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
