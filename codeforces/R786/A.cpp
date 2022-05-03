#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll x, y;
    cin >> x >> y;
    if (y % x == 0) {
        cout << 1 << " " << y / x << "\n";
    } else {
        cout << "0 0\n";
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