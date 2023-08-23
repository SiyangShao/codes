#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n;
    cin >> n;
    vector<vector<int>> E(n * 2);
    vector<int> vis(n * 2, 0);
    vector<ll> cycle;
    // vector<int> match(n,-1);
    function<void(int)> dfs = [&](int u) {
        cycle.emplace_back(u);
        vis[u] = 1;
        for (auto v : E[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };
    for (int i = 0; i < n * 2; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    ll ans = 0;
    for (int center = 0; center < n; ++center) {
        if (vis[center]) {
            continue;
        }
        cycle.clear();
        dfs(center);
        int sz = cycle.size();
        assert(sz % 2 == 0);
        for (int j = 0; j < sz; ++j) {
            cycle.emplace_back(cycle[j]);
        }
        for (int i = 0; i < sz; ++i) {
            ll mnL, mnR, mxL, mxR;
            if (cycle[i] < n) {
                mnL = mxL = cycle[i];
                mnR = mxR = cycle[i + 1];
            } else {
                mnL = mxL = cycle[i + 1];
                mnR = mxR = cycle[i];
            }
            for (int j = i + 2; j <= i + sz; ++j) {
                if ((j - i) % 2 == 0) {
                    ans +=
                        (mnL + 1) * (n - mxL) * (mnR - n + 1) * (n * 2 - mxR);
                } else {
                    ans -=
                        (mnL + 1) * (n - mxL) * (mnR - n + 1) * (n * 2 - mxR);
                }
                if (cycle[j] < n) {
                    mxL = max(mxL, cycle[j]);
                    mnL = min(mnL, cycle[j]);
                } else {
                    mxR = max(mxR, cycle[j]);
                    mnR = min(mnR, cycle[j]);
                }
            }
            if (i == 0) {
                ans -= sz / 2LL * (mnL + 1) * (n - mxL) * (mnR - n + 1) *
                       (n + n - mxR);
            }
        }
    }
    cout << ans << "\n";
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