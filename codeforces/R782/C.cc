#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    vector<ll> x(n + 1);
    x[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    vector<ll> pre(n + 1);
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + x[i];
    }
    ll ans = LONG_LONG_MAX;
    for (int i = 0; i <= n; ++i) {
        // move here
        ll cur = x[i] * (a + b) + (pre[n] - pre[i] - x[i] * (n - i)) * b;
        ans = min(ans, cur);
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