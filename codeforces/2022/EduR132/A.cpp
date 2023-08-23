#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll x;
    cin >> x;
    array<ll, 4> a;
    cin >> a[1] >> a[2] >> a[3];
    if (a[x] == 0) {
        cout << "NO\n";
        return;
    }
    for (ll i = 1; i <= 3; ++i) {
        if (a[i] == i) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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