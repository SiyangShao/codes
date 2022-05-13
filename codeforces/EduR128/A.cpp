#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;
    auto res = l1 + l2;
    for (ll i = l1; i <= r1; ++i) {
        if (i <= r2 && i >= l2) {
            cout << i << "\n";
            return;
        }
    }
    cout << l1 + l2 << "\n";
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