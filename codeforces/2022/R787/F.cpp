#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, k, x, y;
    cin >> n >> k >> x >> y;
    x--, y--;
    vector<ll> a(k);
    vector<ll> st(n), val(n);
    st.assign(n, 0), val.assign(n, 0);
    for (auto &i : a) {
        cin >> i;
        i--;
        st[i] = 1;
    }
    vector<vector<ll>> E(n);
    E.assign(n, vector<ll>());
    for (auto i = 1LL; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v), E[v].emplace_back(u);
    }
    ll ans = 0;
    auto dfs = [&](auto self, auto u, auto fa) -> ll {
        ll flag = 0;
        if (u == y)
            flag = max(flag, 2LL);
        if (st[u]) {
            flag = max(flag, 1LL);
        }
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            auto tmp = self(self, v, u);
            flag = max(flag, tmp);
            if (tmp == 0) {
                continue;
            } else if (tmp == 1) {
                ans += (val[v] + 1) * 2;
            } else {
                ans += val[v] + 1;
            }
        }
        return flag;
    };
    dfs(dfs, x, -1);
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