#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
vector<ll> a, vis;
vector<vector<ll>> E;
auto circle(ll k) {
    bool is_DAG = false;
    auto dfs = [&](auto self, ll u) {
        if (is_DAG)
            return;
        vis[u] = 1;
        for (auto v : E[u]) {
            if (a[v] > k)
                continue;
            if (vis[v] == 1) {
                is_DAG = true;
                return;
            } else if (vis[v] == -1) {
                continue;
            } else {
                self(self, v);
            }
        }
        vis[u] = -1;
    };
    vis.assign(n, 0);
    for (ll i = 0; i < n; ++i) {
        if (!vis[i] && a[i] <= k) {
            dfs(dfs, i);
            if (is_DAG)
                return true;
        }
    }
    return false;
}
auto len(ll k) {
    vis.assign(n, 0);
    vector<ll> val(n);
    val.assign(n, 1);
    auto dfs = [&](auto self, ll u) -> void {
        vis[u] = 1;
        for (auto v : E[u]) {
            if (a[v] > k) {
                continue;
            } else {
                if (!vis[v]) {
                    self(self, v);
                }
                val[u] = max(val[u], val[v] + 1);
            }
        }
    };
    for (ll i = 0; i < n; ++i) {
        if (!vis[i] && a[i] <= k) {
            dfs(dfs, i);
        }
    }
    return *max_element(val.begin(), val.end());
}
auto judge(ll num, ll k) { return circle(num) || (len(num) >= k); }
auto solve() {
    ll k;
    cin >> n >> m >> k;
    a.assign(n, 0);
    E.assign(n, vector<ll>());
    vector<ll> sum;
    for (auto &i : a) {
        cin >> i;
        sum.emplace_back(i);
    }
    sort(sum.begin(), sum.end());
    sum.erase(unique(sum.begin(), sum.end()), sum.end());
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
    }

    ll l = 0, r = sum.size() - 1;
    if (!judge(sum[r], k)) {
        cout << "-1\n";
        return;
    }
    while (l <= r) {
        auto mid = (l + r) / 2;
        if (judge(sum[mid], k)) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << sum[l] << "\n";
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