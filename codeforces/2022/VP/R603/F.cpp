#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2010;
array<ll, N> l, r, siz, dp;
array<vector<ll>, N> E;
array<array<ll, N>, N> Upper, Lower;
auto solve() {
    ll n, a, b;
    cin >> n;
    // upper part
    cin >> a;
    fill(l.begin(), l.end(), a + 1), fill(r.begin(), r.end(), 0);
    fill(E.begin(), E.end(), vector<ll>());
    fill(siz.begin(), siz.begin(), 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            Upper[i][j] = Lower[i][j] = 0;
        }
    }
    for (int i = 2, tmp; i <= a; ++i) {
        cin >> tmp;
        E[tmp].emplace_back(i);
    }
    for (int i = 1, tmp; i <= n; ++i) {
        cin >> tmp;
        l[tmp] = i;
        r[tmp] = i;
    }
    function<void(int)> dfs1 = [&](int u) {
        if (u != 1) {
            siz[u] = 1;
        } else {
            siz[u] = 0;
        }
        for (auto v : E[u]) {
            dfs1(v);
            siz[u] += siz[v];
            l[u] = min(l[u], l[v]);
            r[u] = max(r[u], r[v]);
        }
        Upper[l[u]][r[u]] = max(Upper[l[u]][r[u]], siz[u]);
    };
    dfs1(1);
    // lower part
    cin >> b;
    fill(l.begin(), l.end(), b + 1), fill(r.begin(), r.end(), 0);
    fill(E.begin(), E.end(), vector<ll>());
    fill(siz.begin(), siz.begin(), 0);
    for (int i = 2, tmp; i <= b; ++i) {
        cin >> tmp;
        E[tmp].emplace_back(i);
    }
    for (int i = 1, tmp; i <= n; ++i) {
        cin >> tmp;
        l[tmp] = i;
        r[tmp] = i;
    }
    function<void(int)> dfs2 = [&](int u) {
        if (u != 1) {
            siz[u] = 1;
        } else {
            siz[u] = 0;
        }
        for (auto v : E[u]) {
            dfs2(v);
            siz[u] += siz[v];
            l[u] = min(l[u], l[v]);
            r[u] = max(r[u], r[v]);
        }
        Lower[l[u]][r[u]] = max(Lower[l[u]][r[u]], siz[u]);
    };
    dfs2(1);
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            dp[j] = max(dp[j], dp[i - 1] + max(Upper[i][j], Lower[i][j]));
            // cout << Upper[i][j] << " " << Lower[i][j] << "\n";
        }
    }
    cout << dp[n] << "\n";
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