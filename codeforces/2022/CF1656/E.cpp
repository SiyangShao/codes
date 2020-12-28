#include <iostream>
#include <vector>
using ll = long long;
auto solve() {
    ll n;
    std::cin >> n;
    std::vector<std::vector<ll>> E(n);
    for (ll i = 1, u, v; i < n; ++i) {
        std::cin >> u >> v;
        u--, v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    std::vector<ll> ans(n);
    auto dfs = [&](auto self, auto u, auto fa, auto x) -> void {
        ans[u] = x;
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            self(self, v, u, x == 0 ? 1 : -x);
            ans[u] -= x == 0 ? 1 : -x;
        }
    };
    dfs(dfs, 0, -1, 0);
    for (auto i : ans) {
        std::cout << i << " ";
    }
    std::cout << "\n";
}
auto main() -> int {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int _;
    std::cin >> _;
    while (_--) {
        solve();
    }
}