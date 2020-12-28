#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m, k;
    cin >> n >> m >> k;
    vector<vector<ll>> E(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v), E[v].emplace_back(u);
    }
    if (k == 1) {
        cout << n << "\n";
        return;
    }
    /**
     * @brief
     * ASSUME: If we could have a path lengh is x, we CAN have another path
     * length is x+2. if x is even, gcd(x,x+2) == 2, else gcd(x,x+2) ==
     * gcd(2b+1,2b-1) = 1. So if k = 1 or 2 is the only answer.
     */
    if (k >= 3) {
        cout << "1\n";
        return;
    }
    vector<ll> col(n, -1);
    function<bool(int, int)> dfs = [&](int u, int c) {
        col[u] = c;
        bool ans = true;
        for (auto v : E[u]) {
            if (col[v] == col[u]) {
                return false;
            } else if (col[v] == -1) {
                ans = ans & dfs(v, c ^ 1);
            }
        }
        return ans;
    };
    bool ans = true;
    for (int i = 0; i < n; ++i) {
        if (col[i] == -1) {
            ans = ans & dfs(i, 0);
        }
    }
    if (ans) {
        ll white = 0, black = 0;
        for (int i = 0; i < n; ++i) {
            if (col[i]) {
                black++;
            } else {
                white++;
            }
        }
        cout << max(black, white) << "\n";
    } else {
        cout << "1\n";
    }
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