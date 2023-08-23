// https://ac.nowcoder.com/acm/contest/26077/1001
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, p;
    cin >> n >> p;
    vector<pair<ll, ll>> s(n);
    for (auto &[c, u] : s) {
        cin >> c >> u;
    }
    vector<vector<pair<ll, ll>>> E(n);
    vector<ll> vis(n, 0);
    for (ll i = 0; i < p; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        E[u].emplace_back(v, w);
        vis[v]++;
    }
    queue<ll> Q;
    for (ll i = 0; i < n; ++i) {
        if (vis[i] == 0) {
            s[i].first += s[i].second;
            Q.emplace(i);
        }
    }
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        s[u].first -= s[u].second;
        if (s[u].first <= 0)
            continue;
        for (auto [v, w] : E[u]) {
            s[v].first += w * s[u].first;
            vis[v]--;
            if (vis[v] == 0)
                Q.emplace(v);
        }
    }
    bool flag = false;
    vector<ll> ans;
    for (ll i = 0; i < n; ++i) {
        if (E[i].size() == 0 && s[i].first > 0) {
            ans.emplace_back(i);
        }
    }
    if (ans.empty()) {
        cout << "NULL\n";
    } else {
        for (auto i : ans) {
            cout << i + 1 << " " << s[i].first << "\n";
        }
    }
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}