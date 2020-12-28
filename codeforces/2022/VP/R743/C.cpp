#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
vector<vector<ll>> E;
vector<vector<ll>> lst;
vector<ll> topo, c, d;
auto toposort() {
    c.assign(n, 0);
    lst.clear();
    topo.clear();
    d.assign(n, 1);
    auto dfs = [&](auto self, auto u) {
        c[u] = -1;
        for (auto v : E[u]) {
            if (c[v] < 0) {
                return false;
            } else if (!c[v]) {
                if (!self(self, v)) {
                    return false;
                }
            }
            if (v < u) {
                d[u] = max(d[v], d[u]);
            } else {
                d[u] = max(d[v] + 1, d[u]);
            }
        }
        c[u] = 1;
        topo.emplace_back(u);
        return true;
    };
    for (ll u = 0; u < n; ++u) {
        if (!c[u]) {
            topo.clear();
            if (!dfs(dfs, u))
                return false;
            lst.emplace_back(topo);
        }
    }
    return true;
}
auto solve() {
    cin >> n;
    E.assign(n, vector<ll>());
    for (ll i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; ++j) {
            ll v;
            cin >> v;
            v--;
            E[i].emplace_back(v);
        }
    }
    if (toposort()) {
        cout << *max_element(d.begin(), d.end()) << "\n";
    } else {
        cout << "-1\n";
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