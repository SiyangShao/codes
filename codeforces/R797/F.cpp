#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> p(n);
    for (auto &i : p) {
        cin >> i;
        i--;
    }
    vector<ll> vis(n);
    vis.assign(n, 0);
    vector<ll> lst;
    auto dfs = [&](auto self, auto u) {
        if (vis[u]) {
            return;
        }
        lst.emplace_back(s[u] - 'a');
        vis[u] = 1;
        self(self, p[u]);
    };
    auto judge = [&]() {
        auto new_lst = lst;
        ll n = lst.size();
        for (ll i = 1; i < n; ++i) {
            for (ll j = 0; j < n; ++j) {
                new_lst[j] = lst[(i + j) % n];
            }
            if (new_lst == lst) {
                return i;
            }
        }
        return n;
    };
    ll ans = 1;
    for (ll i = 0; i < n; ++i) {
        if (!vis[i]) {
            lst.clear();
            dfs(dfs, i);
            auto tmp = judge();
            ans = lcm(ans, tmp);
        }
    }
    cout << ans << "\n";
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