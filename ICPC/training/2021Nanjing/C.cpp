#include <bits/stdc++.h>
using namespace std;
using ll = int;
constexpr ll N = 5e6;
constexpr ll BS = 2e6;
array<vector<ll>, N> mp;
array<ll, N> x, y;
auto solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    if (k == 0) {
        ll ans = 0;
        for (auto &i : a) {
            cin >> i;
            i += BS;
            mp[i].emplace_back(i);
            ans = max(ans, ll(mp[i].size()));
        }
        cout << ans << "\n";
        return;
    }
    ll ans = 0;
    ll L = N, R = 0;
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i] += BS;
        R = max(R, a[i]);
        R = max(R, a[i] + k);
        L = min(L, a[i]);
        L = min(L, a[i] + k);
        mp[a[i]].emplace_back(a[i]);
        mp[a[i] + k].emplace_back(a[i]);
    }
    for (ll num = L; num <= R; ++num) {
        if (mp[num].empty())
            continue;
        ll m = mp[num].size();
        x[0] = 0, y[0] = 0;
        for (ll i = 0; i < m; ++i) {
            x[i + 1] = x[i] + (mp[num][i] == num);
            y[i + 1] = y[i] + (mp[num][i] != num);
        }
        ans = max(ans, x[num]);
        ll tmp = 0;
        for (ll i = 1; i <= m; ++i) {
            tmp = max(tmp, x[i - 1] - y[i - 1]);
            ans = max(ans, x[m] + y[i] - x[i] + tmp);
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