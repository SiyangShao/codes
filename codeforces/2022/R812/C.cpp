#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> sqr;
    for (ll i = 0; i < n; ++i) {
        if (i * i <= n + n) {
            sqr.emplace_back(i * i);
        } else {
            break;
        }
    }
    vector<vector<ll>> E(n);
    ll m = 0;
    for (int i = 0; i < n; ++i) {
        // cout<<i<<": ";
        for (auto j : sqr) {
            if (j - i < n && j - i >= 0) {
                E[i].emplace_back(j - i);
                m++;
                // cout<<j-i<<" ";
            }
        }
        // cout<<"\n";
    }
    cout<<m<<"\n";
    vector<ll> vis(n), link(n);
    fill(link.begin(), link.end(), -1);
    function<bool(int)> dfs = [&](int u) {
        for (auto v : E[u]) {
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
        // dfs(i) x times means add x points same as point i in the map
        if (dfs(i)) {
            cnt++;
        } else {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << link[i] << " ";
    }
    cout << "\n";
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