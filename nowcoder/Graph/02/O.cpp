#include <bits/stdc++.h>
using namespace std;
constexpr int N = 10010;
bitset<N> vis, can;
auto solve() {
    int n;
    cin >> n;
    vector<vector<int>> E(10010);
    for (int i = 0; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    function<bool(int)> dfs = [&](int u) {
        if (!vis[u]) {
            if (E[u].empty()) {
                return false;
            }
            vis[u] = true;
            int mxp = u, nume = 0, nump = 0;
            queue<int> Q;
            Q.emplace(u);
            while (!Q.empty()) {
                auto x = Q.front();
                Q.pop();
                nump++;
                mxp = max(mxp, x);
                for (auto v : E[x]) {
                    nume++;
                    if (!vis[v]) {
                        vis[v] = true;
                        Q.emplace(v);
                    }
                }
            }
            nume /= 2;
            if (nume < nump) {
                can[mxp] = true;
            }
        }
        return bool(!can[u]);
        // return true;
    };
    for (int i = 1; i <= 10000; ++i) {
        if (!dfs(i)) {
            cout << i - 1 << "\n";
            return;
        }
    }
    cout << 10000 << "\n";
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