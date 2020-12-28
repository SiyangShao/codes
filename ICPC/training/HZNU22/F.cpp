#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n + 1);
    map<ll, ll> res;
    a[0] = 0;
    res.clear();
    res[0] = 1;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        a[i] += a[i - 1];
        res[a[i] % k]++;
    }
    ll ans = 0;
    for (auto &[_, i] : res) {
        if (i == 0)
            continue;
        ans += i * (i - 1) / 2;
    }
    cout << ans << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
}