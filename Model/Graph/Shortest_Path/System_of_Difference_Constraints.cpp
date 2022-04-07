#include "bits/stdc++.h"
#include <climits>
using namespace std;
using ll = long long;
ll n, m;
vector<vector<pair<ll, ll>>> E;
vector<ll> dis, cnt, vis;
auto spfa(ll s = 0) {
    dis.assign(n + 1, INT_MAX);
    cnt.assign(n + 1, 0);
    vis.assign(n + 1, 0);
    queue<ll> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        vis[u] = 0;
        for (auto [v, w] : E[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                cnt[v] = cnt[v] + 1;
                if (cnt[v] > n) {
                    return false;
                }
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return true;
}
auto solve() {
    cin >> n >> m;
    E.resize(n + 1);
    for (ll i = 0, u, v, w; i < m; ++i) {
        cin >> v >> u >> w;
        // v - u <= w
        E[u].emplace_back(v, w);
    }
    for (ll i = 1; i <= n; ++i) {
        E[0].emplace_back(i, 0);
    }
    if (spfa()) {
        for(ll i = 1; i <=n;++i){
            cout<<dis[i]<<" ";
        }
    } else {
        cout << "NO\n";
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