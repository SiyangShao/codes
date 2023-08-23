#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n), pre(n + 1);
    for (auto &i : a) {
        cin >> i;
    }
    sort(a.begin(), a.end());
    pre[0] = 0;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + a[i - 1];
    }
    auto pos = upper_bound(pre.begin(), pre.end(), x) - 1 - pre.begin();
    ll k = 0, ans = 0;
    for (int i = pos; i > 0; --i) {
        pre[i] += i * k;
        // cout << pre[i] << " ";
        ll k_max = (x - pre[i] + i) / i;
        k_max = max(0LL, k_max);
        k += k_max;
        // cout << i << " " << k_max << "\n";
        ans += k_max * i;
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