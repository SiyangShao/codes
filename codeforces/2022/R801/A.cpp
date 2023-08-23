#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16 + 7;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mp(n, vector<ll>(m));
    ll MAXN = -inf, x = -1, y = -1;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> mp[i][j];
            if (mp[i][j] > MAXN) {
                MAXN = mp[i][j];
                x = i, y = j;
            }
        }
    }
    ll ans = 0;
    ans = max(ans, (x + 1) * (y + 1));
    ans = max(ans, (x + 1) * (m - y));
    ans = max(ans, (n - x) * (y + 1));
    ans = max(ans, (n - x) * (m - y));
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