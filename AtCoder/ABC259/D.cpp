#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n;
    cin >> n;
    atcoder::dsu DSU(n + 2);
    pair<ll, ll> S, T;
    cin >> S.first >> S.second >> T.first >> T.second;
    vector<array<ll, 3>> p(n);
    auto check = [&](ll x, ll y, ll a, ll b, ll r1, ll r2) {
        ll dis = (x - a) * (x - a) + (y - b) * (y - b);
        ll r = r1 + r2;
        ll R = abs(r1 - r2);
        if (dis <= r * r && dis >= R * R) {
            return true;
        }
        return false;
    };
    ll cnt = 0;
    for (auto &[x, y, r] : p) {
        cin >> x >> y >> r;
        if ((x - S.first) * (x - S.first) + (y - S.second) * (y - S.second) ==
            r * r) {
            DSU.merge(n, cnt);
        }
        if ((x - T.first) * (x - T.first) + (y - T.second) * (y - T.second) ==
            r * r) {
            DSU.merge(n + 1, cnt);
        }
        cnt++;
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = i + 1; j < n; ++j) {
            if (check(p[i][0], p[i][1], p[j][0], p[j][1], p[i][2], p[j][2])) {
                DSU.merge(i, j);
            }
        }
    }
    if (DSU.same(n, n + 1)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
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