#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    vector<vector<ll>> E;
    E.assign(n, vector<ll>());
    for (ll i = 1; i < n; ++i) {
        ll p;
        cin >> p;
        p--;
        E[p].emplace_back(i);
    }
    vector<ll> l(n), r(n);
    for (ll i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
    }
    ll ans = 0;
    auto dfs = [&](auto self, auto u) -> pair<ll, ll> {
        ll round = 0, cnt = 0;
        for (auto v : E[u]) {
            auto [nxt_rnd, nxt_cnt] = self(self, v);
            // cout << v << " " << nxt_rnd << " " << nxt_cnt << "\n";
            round += nxt_rnd;
            cnt += nxt_cnt;
        }
        if (cnt >= l[u]) {
            cnt = min(cnt, r[u]);
            return {round, cnt};
        } else {
            return {round + 1, r[u]};
        }
    };
    cout << dfs(dfs, 0).first << "\n";
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