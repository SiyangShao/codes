#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using i128 = __int128;
map<i128, ll> mp;
auto solve() {
    ll n, x;
    cin >> n >> x;
    i128 nxt = x, N = 1;
    for (ll i = 1; i < n; ++i) {
        N *= 10;
    }
    auto dfs = [&](auto self, auto x) {
        if (x >= N) {
            return 0LL;
        }
        if (mp.contains(x)) {
            return mp[x];
        }
        ll res = 64;
        mp[x] = res;
        auto tmp = x;
        while (tmp) {
            auto nxt = tmp % 10;
            if (nxt >= 2) {
                res = min(res, 1 + self(self, x * nxt));
                mp[x] = res;
            }
            tmp /= 10;
        }
        mp[x] = res;
        return res;
    };
    auto ans = dfs(dfs, nxt);
    if (ans == 64) {
        cout << "-1\n";
    } else {
        cout << ans << "\n";
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