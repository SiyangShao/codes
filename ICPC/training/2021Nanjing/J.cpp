#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1e9 + 7;
vector<ll> pri;
unordered_map<ll, ll> mp;
inline auto Hash(ll u, ll v) { return u * INF + v; }
auto dfs(ll u, ll diff) {
    if (u == 1) {
        return 0LL;
    }
    if (diff == 1) {
        return u - 1;
    }
    if (mp.contains(Hash(u, diff)))
        return mp[Hash(u, diff)];
    ll ans = u - 1;
    for (auto v : pri) {
        if (diff % v == 0) {
            ll res = u % v;
            ans = min(ans, res + 1 + dfs(u / v, diff / v));
            ans = min(ans, v - res + 1 + dfs(u / v + 1, diff / v));
        }
    }
    return mp[Hash(u, diff)] = ans;
}
auto sol(ll a, ll b) {
    pri.clear();
    ll c = abs(a - b);
    for (ll i = 2; i * i <= c; ++i) {
        if (c % i == 0) {
            while (c % i == 0) {
                c /= i;
            }
            pri.emplace_back(i);
        }
    }
    if (c != 1) {
        pri.emplace_back(c);
    }
}
auto solve() {
    ll a, b;
    cin >> a >> b;
    if (a > b) {
        swap(a, b);
    }
    sol(a, b);
    b = b - a;
    cout << dfs(a, b) << "\n";
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