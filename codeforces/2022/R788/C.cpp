#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9 + 7;
// C++ Version
long long qpow(long long a, long long b, long long m = MOD) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b % 2 == 1)
            res = (res * a) % m;
        a = (a * a) % m;
        b /= 2LL;
    }
    return res;
}
vector<ll> E, vis, flg;
bool dfs(ll u) {
    if (vis[u]) {
        return flg[u] != 1;
    }
    vis[u] = 1;
    auto ans = dfs(E[u]);
    return (ans && flg[u] != 1);
}
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    vis.assign(n + 1, 0);
    E.assign(n + 1, -1);
    flg.assign(n + 1, 0);
    for (auto &i : a) {
        cin >> i;
    }
    for (auto &i : b) {
        cin >> i;
    }
    for (auto &i : c) {
        cin >> i;
        flg[i] = 1;
    }
    for (int i = 0; i < n; ++i) {
        E[a[i]] = b[i];
    }
    ll cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (E[i] == i)
            continue;
        if (!vis[i]) {
            if (dfs(i)) {
                // cout << i << " ";
                cnt++;
            }
        }
    }
    // cout << cnt << " ";
    cout << qpow(2, cnt) << "\n";
}
auto main() -> int {
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}