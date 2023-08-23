#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll l, r;
    cin >> l >> r;
    vector<ll> a(r - l + 1);
    for (auto &i : a) {
        cin >> i;
    }
    ll ans = 0, bs = 1;
    for (ll i = 0; i < 20; ++i) {
        ll cnt = 0;
        for (ll j = 0; j <= r; ++j) {
            if (a[j] & bs)
                cnt++;
            if (j & bs)
                cnt--;
        }
        if (cnt != 0) {
            ans += bs;
        }
        bs <<= 1;
    }
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