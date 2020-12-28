#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
array dx = {0, -1, 0, 1, -1, -1, 1, 1};
array dy = {1, 0, -1, 0, -1, 1, 1, -1};
array<ll, 12> qpow;
auto solve() {
    ll n;
    cin >> n;
    vector<string> mp(n);
    vector vis(n, vector<ll>(n, 0));
    for (auto &i : mp) {
        cin >> i;
    }
    map<array<ll, 3>, ll> ans;
    function<ll(ll, ll, ll, ll)> dfs = [&](ll x, ll y, ll d, ll stp) {
        ll nx = (x + dx[d] + n) % n;
        ll ny = (y + dy[d] + n) % n;
        if (stp == n) {
            return ll(mp[x][y] - '0');
        }
        return (mp[x][y] - '0') + 10LL * dfs(nx, ny, d, stp + 1);
    };
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            for (ll d = 0; d < 8; ++d) {
                res = max(res, dfs(i, j, d, 1));
            }
        }
    }
    cout << res << "\n";
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    qpow[0] = 1;
    for (ll i = 1; i < 15; ++i) {
        qpow[i] = qpow[i - 1] * 10;
    }
    // cin >> _;
    while (_--) {
        solve();
    }
}