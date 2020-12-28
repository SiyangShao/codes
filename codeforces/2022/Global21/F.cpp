#include <bits/stdc++.h>
using namespace std;
auto solve() {
    int n;
    cin >> n;
    vector mp(n, vector<string>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> mp[i][j];
            mp[j][i] = mp[i][j];
        }
    }
    for (int x = 1; x < n; ++x) {
        vector<bool> vis(n, false);
        vis[0] = true, vis[x] = true;
        vector<pair<int, int>> edge;
        edge.emplace_back(0, x);
        function<void(int, int)> check =
            [&](int u, int v) {
                for (int i = 0; i < n; ++i) {
                    if (vis[i] || mp[i][u][v] == '0')
                        continue;
                    vis[i] = true;
                    edge.emplace_back(v, i);
                    check(v, i);
                }
            }

        ;
        check(0, x);
        check(x, 0);
        if (edge.size() != n - 1) {
            continue;
        }
        vector<vector<int>> E(n);
        for (auto &[u, v] : edge) {
            E[u].emplace_back(v);
            E[v].emplace_back(u);
        }
        vector dis(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            function<void(int, int)> dfs = [&](int u, int p) {
                for (auto v : E[u]) {
                    if (v == p)
                        continue;
                    dis[i][v] = dis[i][u] + 1;
                    dfs(v, u);
                }
            };
            dfs(i, -1);
        }
        bool flag = true;
        for (int x = 0; x < n; ++x) {
            for (int y = x + 1; y < n; ++y) {
                for (int z = 0; z < n; ++z) {
                    if ((mp[x][y][z] == '1') != (dis[x][z] == dis[y][z])) {
                        flag = false;
                    }
                }
            }
        }

        if (flag) {
            cout << "Yes\n";
            for (auto [u, v] : edge) {
                cout << u + 1 << " " << v + 1 << "\n";
            }
            return;
        }
    }
    cout << "No\n";
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