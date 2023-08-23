#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<string> mp(n);
    vector<vector<ll>> E(n + 26);
    for (auto &i : mp) {
        cin >> i;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < mp[i].length(); ++j) {
            E[i].emplace_back(n + mp[i][j] - 'a');
            E[n + mp[i][j] - 'a'].emplace_back(i);
        }
    }
    vector<bool> vis(n + 26, false);
    function<void(int)> dfs = [&](int u) {
        vis[u] = true;
        for (auto v : E[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };
    ll ans = 0;
    for (int i = n; i < n + 26; ++i) {
        if (!E[i].empty() && !vis[i]) {
            dfs(i);
            ans++;
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