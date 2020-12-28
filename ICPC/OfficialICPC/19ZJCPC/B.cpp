#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    string s;
    cin >> s;
    ll n = s.size();
    for (ll i = 0; i < min(2LL, n); ++i) {
        cout << s[i];
    }
    for (ll i = 2; i < n; ++i) {
        cout << s[i];
        if (s[i] == 'b' && s[i - 1] == 'j' && s[i - 2] == 'c') {
            cout << ",";
        }
    }
    cout << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}