#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    ll b = 0, cur = 0;
    for (ll i = 0; i < k; ++i) {
        if (s[i] == 'W') {
            b++;
        }
    }
    cur = b;
    for (ll i = 0; i + k < n; ++i) {
        cur -= (s[i] == 'W' ? 1 : 0);
        cur += (s[i + k] == 'W' ? 1 : 0);
        b = min(b, cur);
    }
    cout << b << "\n";
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