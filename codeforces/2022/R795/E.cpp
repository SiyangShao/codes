#include <bits/stdc++.h>
using namespace std;
using ll = long long;
class DSU {
  public:
    vector<ll> fa, siz;
    ll n;
    DSU(ll _n) : n(_n) {
        fa.resize(n);
        iota(fa.begin(), fa.end(), 0);
        siz.assign(n, 1);
    }
    auto find(ll u) {
        if (u == fa[u])
            return fa[u];
        return fa[u] = find(fa[u]);
    }
    auto merge(ll u, ll v) {
        u = find(u), v = find(v);
        if (u == v)
            return 0;
        if (siz[u] > siz[v])
            swap(u, v);
        fa[u] = v;
        siz[v] += siz[u];
        return 1;
    }
};
auto solve() {
    ll n;
    cin >> n;
    vector<ll> c(n), l(n), r(n);
    vector<pair<ll, ll>> ev;
    for (ll i = 0; i < n; ++i) {
        cin >> c[i] >> l[i] >> r[i];
        ev.emplace_back(l[i], ~i);
        ev.emplace_back(r[i], i);
    }
    sort(ev.begin(), ev.end());
    vector<set<pair<ll, ll>>> s(2);
    DSU dsu(n);
    ll ans = n;
    for (auto &[pos, id] : ev) {
        if (id < 0) {
            id = ~id;
            s[c[id]].emplace(r[id], id);
            auto q = c[id] ^ 1;
            if (!s[q].empty()) {
                while (s[q].size() >= 2) {
                    ans -= dsu.merge(id, s[q].begin()->second);
                    s[q].erase(s[q].begin());
                }
                ans -= dsu.merge(id, s[q].begin()->second);
            }
        } else {
            s[c[id]].erase({r[id], id});
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