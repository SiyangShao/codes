#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mp(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        mp[u][v] = 1;
    }
    int res = 1e9;
    vector<int> link(n), vis(n);
    for (int center = 0; center < n; ++center) {
        fill(link.begin(), link.end(), -1);
        int ans = 0, sum = 0;
        for (int i = 0; i < n; ++i) {
            if (mp[center][i]) {
                sum++;
            } else {
                ans++;
            }
            if (mp[i][center]) {
                sum++;
            } else {
                ans++;
            }
        }
        sum -= mp[center][center];
        ans -= mp[center][center] ^ 1;
        int cnt = 0;
        function<bool(int)> dfs = [&](int x) {
            for (int i = 0; i < n; i++) {

                if (vis[i] || !mp[x][i] || i == center)
                    continue;
                vis[i] = 1;
                if (link[i] == -1 || dfs(link[i])) {
                    link[i] = x;
                    return true;
                }
            }
            return false;
        };
        for (int i = 0; i < n; ++i) {
            if (i == center)
                continue;
            fill(vis.begin(), vis.end(), 0);
            if (dfs(i))
                cnt++;
        }
        ans += n - 1 - cnt;
        ans += m - cnt - sum;
        res = min(res, ans);
    }
    cout << res << "\n";
}