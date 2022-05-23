#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    ll m, ans = 0;
    cin >> m;
    for (ll i = 0; i < m; ++i) {
        ll cnt;
        cin >> cnt;
        ans += cnt;
    }
    cout << a[ans % n] << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    ll _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}