#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
constexpr ll MOD = 998244353;
constexpr ll N = 2e5 + 7;
int n;
vector<pair<ll, pair<ll, ll>>> E[N];
pair<ll, ll> val[N];
void dfs(ll u) {
    for (auto &[v, w] : E[u]) {
        if (val[v].second == 0) {
            auto x = val[u].first * w.second ;
            auto y = val[u].second * w.first;
            auto z = gcd(x, y);
            x /= z, y /= z;
            x %= MOD, y %= MOD;
            val[v] = {x, y};
            dfs(v);
        }
    }
}
pair<ll, ll> add(pair<ll, ll> x, pair<ll, ll> y) {
    ll up = (x.first * y.second + x.second * y.first) % MOD;
    ll down = x.second * y.second % MOD;
    // ll z = gcd(up, down);
    // up /= z, down /= z;
    // up %= MOD, down %= MOD;
    return {up, down};
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        E[i].clear();
        val[i] = {0, 0};
    }
    for (ll i = 1, u, v, x, y; i < n; ++i) {
        cin >> u >> v >> x >> y;
        E[u].push_back({v, {x, y}});
        E[v].push_back({u, {y, x}});
    }
    val[1] = {1, 1};
    dfs(1);
    pair<ll, ll> ans = {1, 1};
    // cout << "\n";
    // for (int i = 1; i <= n; ++i) {
    //     cout << val[i].first << " " << val[i].second << "\n";
    // }
    for (int i = 2; i <= n; ++i) {
        ans = add(ans, val[i]);
    }
    auto tmp = gcd(ans.first, ans.second);
    cout << ans.first / tmp << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}