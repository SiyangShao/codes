#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    map<ll, vector<ll>> E;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        E[a[i]].emplace_back(i);
    }
    ll ans = n * (n - 1) * (n - 2) / 6;
    for (auto &[_, val] : E) {
        auto siz = val.size();
        if (siz <= 1) {
            continue;
        } else if (siz == 2) {
            ans -= (n - siz);
        } else {
            ans -= siz * (siz - 1) * (siz - 2) / 6;
            ans -= siz * (siz - 1) / 2 * (n - siz);
        }
    }
    cout << ans << "\n";
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