#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 55;
constexpr ll V = 550;
array<array<ll, N>, N> mp, mpr;
inline auto pl(ll x, ll op = 1) { return x + V * op; }
inline auto id(ll x, ll op = 1) { return x + V * N * op; }
array<array<ll, V * 2>, N> f;
array<array<ll, N * V * 2>, N> g;
array<set<ll>, N> st;
auto dp(array<array<ll, N>, N> &package, ll n, ll m) {
    for (int i = 1; i <= n; ++i) {
        st[i].clear();
        f[i].fill(0);
        for (int j = 1; j <= m; ++j) {
            auto delta = package[i][j] - package[i % n + 1][j];
            st[i].insert(delta);
            f[i][pl(delta)]++;
        }
    }
    for (ll i = 0; i < N; ++i) {
        g[i].fill(-1);
    }
    for (int i = 0; i < V * 2; ++i) {
        g[1][id(pl(i, -1))] = f[1][i];
    }
    for (int i = 2; i <= n; ++i) {
        g[i] = g[i - 1];
        for (auto delta : st[i]) {
            for (auto j = max(0LL, delta);
                 j < N * V * 2 && j - delta < N * V * 2; ++j) {
                if (g[i - 1][j - delta] < 0)
                    continue;
                g[i][j] = max(g[i][j], g[i - 1][j - delta] + f[i][pl(delta)]);
            }
        }
    }
    auto greedy = 0LL, greedy_min = LONG_LONG_MAX;
    for (int i = 1; i <= n; ++i) {
        auto delta = *max_element(f[i].begin(), f[i].end());
        greedy += delta;
        greedy_min = min(greedy_min, delta);
    }
    greedy -= greedy_min;
    return max(greedy, g[n][id(0)]);
}
auto solve() {
    ll n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mp[i][j];
            mpr[j][i] = mp[i][j];
        }
    }
    cout << dp(mp, n, m) + dp(mpr, m, n) << "\n";
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