#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16 + 7;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<vector<ll>> mp(n, vector<ll>(m));
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < m; ++j) {
            cin >> mp[i][j];
        }
    }
    auto MINM = mp;
    auto MAXN = mp;
    for (ll i = 1; i < n; ++i) {
        MAXN[i][0] = MINM[i][0] = MAXN[i - 1][0] + mp[i][0];
    }
    for (ll j = 1; j < m; ++j) {
        MAXN[0][j] = MINM[0][j] = MAXN[0][j - 1] + mp[0][j];
    }
    for (ll i = 1; i < n; ++i) {
        for (ll j = 1; j < m; ++j) {
            MAXN[i][j] = max(MAXN[i - 1][j], MAXN[i][j - 1]) + mp[i][j];
            MINM[i][j] = min(MINM[i - 1][j], MINM[i][j - 1]) + mp[i][j];
        }
    }

    if (MAXN[n - 1][m - 1] % 2 || MINM[n - 1][m - 1] > 0 || MAXN[n - 1][m - 1] < 0) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
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