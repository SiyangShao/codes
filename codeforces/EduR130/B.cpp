#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> p(n);
    for (auto &i : p) {
        cin >> i;
    }
    sort(p.begin(), p.end(), greater<>());
    vector<ll> pre(n + 1);
    pre[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + p[i - 1];
    }
    while (q--) {
        ll x, y;
        cin >> x >> y;
        cout << pre[x] - pre[x - y] << "\n";
    }
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