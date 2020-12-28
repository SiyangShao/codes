#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    if (s.length() == 2) {
        cout << s[1] << "\n";
    } else {
        auto mi = '9';
        for (auto i : s) {
            mi = min(mi, i);
        }
        cout << mi << "\n";
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}