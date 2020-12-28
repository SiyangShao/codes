#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    ll dif = a[0] - b[0];
    for (ll i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            cout << "NO\n";
            return;
        } else {
            dif = max(dif, a[i] - b[i]);
        }
    }
    for (ll i = 0; i < n; ++i) {
        if (a[i] - b[i] != dif && b[i] != 0) {
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