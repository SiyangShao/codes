#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int mx = n + 2;
    vector<vector<int>> G(mx);
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        // mp[u][v] = 1;
        G[u].emplace_back(v);
    }
    vector<int> link(m), vis(m);
    fill(link.begin(), link.end(), -1);
    function<bool(int)> dfs = [&](int u) {
        for (auto v : G[u]) {
            if (vis[v])
                continue;
            vis[v] = 1;
            if (link[v] == -1 || dfs(link[v])) {
                link[v] = u;
                return true;
            }
        }
        return false;
    };
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        fill(vis.begin(), vis.end(), 0);
        if (dfs(i)) {
            cnt++;
        }
    }
    int bs = 0;
    const auto blink = link;
    for (int k = 0; k < n; ++k) {
        link = blink;
        G[n] = G[n + 1] = G[k];
        fill(vis.begin(), vis.end(), 0);
        int tmp = 0;
        if (dfs(n)) {
            tmp++;
        }
        fill(vis.begin(), vis.end(), 0);
        if (dfs(n + 1)) {
            tmp++;
        }
        bs = max(bs, tmp);
    }
    cout << cnt + bs << "\n";
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