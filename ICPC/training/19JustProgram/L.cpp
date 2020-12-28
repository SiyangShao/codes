#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e3 + 7;
array<array<ll, N>, N> mp, pre;
ll n, m, h, w;
auto init(ll check_num) {
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            if (mp[i][j] == check_num) {
                pre[i][j] = 0;
            } else if (mp[i][j] < check_num) {
                pre[i][j] = -1;
            } else {
                pre[i][j] = 1;
            }
            pre[i][j] =
                pre[i - 1][j] + pre[i][j - 1] + pre[i][j] - pre[i - 1][j - 1];
        }
    }
}
auto check(ll x) {
    init(x);
    for (ll i = h; i <= n; ++i) {
        for (ll j = w; j <= m; ++j) {
            if (pre[i][j] - pre[i - h][j] - pre[i][j - w] + pre[i - h][j - w] <=
                0) {
                return true;
            }
        }
    }
    return false;
}
auto solve() {
    cin >> n >> m >> h >> w;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            cin >> mp[i][j];
        }
    }
    ll l = 1, r = n * m;
    ll ans;
    while (r >= l) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
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