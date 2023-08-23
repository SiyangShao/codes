#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e5 + 7;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<vector<ll>> E(n);
    for (ll i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    vector<set<ll>> st(n);
    vector<ll> dp(n);
    function<ll(ll, ll)> dfs = [&](ll u, ll fa) {
        dp[u] = a[u];
        if (fa != u) {
            dp[u] ^= dp[fa];
        }
        bool flag = false;
        ll cnt = 0;
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            cnt += dfs(v, u);
            if (st[v].count(a[u] ^ dp[u])) {
                flag = true;
                st[v].clear();
            }
            if (st[v].size() > st[u].size()) {
                swap(st[u], st[v]);
            }
            for (auto x : st[v]) {
                if (st[u].contains(a[u] ^ x)) {
                    flag = true;
                }
            }
            for (auto x : st[v]) {
                st[u].emplace(x);
            }
            st[v].clear();
        }
        if (!flag) {
            st[u].emplace(dp[u]);
        } else {
            st[u].clear();
            cnt++;
        }
        return cnt;
    };
    cout << dfs(0, 0) << "\n";
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