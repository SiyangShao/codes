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
    ll ans = LONG_LONG_MAX;
    for (int pos = 0; pos < n; ++pos) {
        // make b[i] == 0
        ll pre = 0, cnt = 0;
        for (int i = pos - 1; i >= 0; --i) {
            auto tmp = 1 + pre / a[i];
            cnt += tmp;
            pre = a[i] * tmp;
        }
        pre = 0;
        for (int i = pos + 1; i < n; ++i) {
            auto tmp = 1 + pre / a[i];
            cnt += tmp;
            pre = a[i] * tmp;
        }
        ans = min(ans, cnt);
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