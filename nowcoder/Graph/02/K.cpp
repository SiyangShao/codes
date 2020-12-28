#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    int n, m;
    cin >> n >> m;
    map<pair<int, int>, int> mp;
    int k = 0;
    vector<vector<int>> col(n, vector<int>(n, -1));
    function<void(int, int, int, int)> dfs = [&](int u, int v, int x, int y) {
        int to = col[v][x];
        col[u][x] = v;
        col[v][x] = u;
        if (to == -1) {
            col[v][y] = -1;
        } else {
            dfs(v, to, y, x);
        }
    };
    vector<int> ans(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        mp[{u, v}] = mp[{v, u}] = i;
        int colx = 0, coly = 0;
        while (col[u][colx] != -1) {
            colx++;
        }
        while (col[v][coly] != -1) {
            coly++;
        }
        // cout<<colx<<" "<<coly<<"?\n";
        k = max(k, max(colx, coly));
        if (colx == coly) {
            col[u][colx] = v;
            col[v][coly] = u;
            continue;
        }
        if (colx > coly) {
            swap(u, v);
            swap(colx, coly);
        }
        dfs(u, v, colx, coly);
    }
    cout << k + 1 << "\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= k; ++j) {
            int v = col[i][j];
            if (v != -1) {
                ans[mp[{i, v}]] = j;
            }
        }
    }
    for (auto i : ans) {
        cout << i + 1 << "\n";
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