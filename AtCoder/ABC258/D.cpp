#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
auto solve() {
    ll n, x;
    cin >> n >> x;
    vector<pair<ll, ll>> a(n);
    for (auto &[l, r] : a) {
        cin >> l >> r;
    }
    ll res = 0, bs = a[0].second, ans = 0;
    for (ll i = 0; i < n; ++i) {
        res += a[i].first + a[i].second;
        bs = min(a[i].second, bs);
        if (ans == 0) {
            ans = res + bs * (x - 1 - i);
        }
        ans = min(ans, res + bs * (x - 1 - i));
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