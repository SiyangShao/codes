#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    vector<ll> mp(m, 0);
    for (auto i : a) {
        ll L = min(i, m + 1 - i), R = max(i, m + 1 - i);
        if (mp[L - 1] == 0) {
            mp[L - 1] = 1;
        } else {
            mp[R - 1] = 1;
        }
    }
    for (ll i = 0; i < m; ++i) {
        if (mp[i]) {
            cout << "A";
        } else {
            cout << "B";
        }
    }
    cout << "\n";
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