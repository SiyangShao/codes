#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    for (auto &[l, r] : p) {
        cin >> l >> r;
    }
    for (auto &[l, r] : p) {
        if (r > l) {
            cout << "NO\n";
            return;
        }
    }
    for (ll i = 1; i < n; ++i) {
        if (p[i].first < p[i - 1].first || p[i].second < p[i - 1].second ||
            (p[i].first - p[i - 1].first < p[i].second - p[i - 1].second)) {
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