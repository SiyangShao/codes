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
    ll ans = 0, pos = a[0];
    for (ll i = 1; i < n; ++i) {
        if (a[i] - a[i - 1] > 0) {
            ans += a[i] - a[i - 1];
        } else {
            ans += a[i - 1] - a[i];
            pos -= a[i - 1] - a[i];
        }
    }
    ans += abs(pos);
    cout << ans << "\n";
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