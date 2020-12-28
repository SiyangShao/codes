#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), vis(n), val(n);
    val.assign(n, 0);
    vector<ll> nxt(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    for (auto &i : b) {
        cin >> i;
        i--;
    }
    for (int i = 0; i < n; ++i) {
        nxt[a[i]] = b[i];
        vis[i] = 0;
    }
    ll l = 1, r = n;
    auto dfs = [&](auto self, auto u, auto level) {
        vis[u] = 1;
        if (vis[nxt[u]] == 1) {
            if (level % 2 == 0) {
                val[u] = (l + r) / 2;
                return;
            } else {
                val[u] = l;
                l++;
                return;
            }
        } else {
            if (level % 2 == 0) {
                val[u] = r;
                r--;
            } else {
                val[u] = l;
                l++;
            }
            self(self, nxt[u], level + 1);
        }
    };
    for (int i = 0; i < n; ++i) {
        if (vis[i] == 0)
            dfs(dfs, i, 0);
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += abs(val[a[i]] - val[b[i]]);
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