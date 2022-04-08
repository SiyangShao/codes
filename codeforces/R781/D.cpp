#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll x = 10;
    ll a, b = 1e9 + 7;
    while (cin >> a) {
        cout << gcd(x + a, x + b) << "\n";
    }
}
auto main() -> int {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}