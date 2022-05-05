#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> dep(n), fa(n), vis(n), lst(n);
    vector<vector<ll>> E;
    ll root = 0;
    E.assign(n, vector<ll>());
    for (auto &i : fa) {
        cin >> i;
        i--;
    }
    for (int i = 0; i < n; ++i) {
        if (fa[i] == i) {
            root = i;
        } else {
            E[fa[i]].emplace_back(i);
        }
    }
    dep.assign(n, 0);
    vis.assign(n, 0);
    iota(lst.begin(), lst.end(), 0);
    auto get_dep = [&](auto self, auto u) -> void {
        for (auto v : E[u]) {
            dep[v] = dep[u] + 1;
            self(self, v);
        }
    };
    get_dep(get_dep, root);
    sort(lst.begin(), lst.end(),
         [&](auto x, auto y) { return dep[x] > dep[y]; });
    vector<vector<ll>> path;
    path.clear();
    vector<ll> res;
    auto dfs = [&](auto self, auto u) {
        if (vis[u] == 1) {
            return;
        }
        vis[u] = 1;
        res.emplace_back(u);
        self(self, fa[u]);
    };
    for (auto i : lst) {
        if (!vis[i]) {
            res.clear();
            dfs(dfs, i);
            reverse(res.begin(), res.end());
            path.emplace_back(res);
        }
    }
    cout << path.size() << "\n";
    for (auto &&i : path) {
        cout << i.size() << "\n";
        for (auto &&v : i) {
            cout << v + 1 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
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