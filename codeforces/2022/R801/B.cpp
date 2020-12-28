#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16 + 7;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    if (n % 2 == 1) {
        cout << "Mike\n";
    } else {
        ll MINM = inf, pos = -1;
        for (ll i = 0; i < n; ++i) {
            if (a[i] < MINM) {
                MINM = a[i];
                pos = i;
            }
        }
        if (pos % 2 == 0) {
            cout << "Joe\n";
        } else {
            cout << "Mike\n";
        }
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