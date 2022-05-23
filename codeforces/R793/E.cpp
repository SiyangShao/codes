#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
        i--;
    }
    vector<vector<ll>> E(n);
    E.assign(n, vector<ll>());
    map<pair<ll, ll>, ll> mp;
    mp.clear();
    for (ll i = 1; i <= m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v), E[v].emplace_back(u);
        mp[{u, v}] = i, mp[{v, u}] = i;
    }
    vector<ll> vis(n);
    vis.assign(n, -1);
    for (ll i = 0; i < n; ++i) {
        if (~vis[i]) {
            continue;
        }
        vector<ll> tmp;
        tmp.clear();
        ll k = 0;
        for (ll j = i; vis[j] == -1; j = a[j]) {
            vis[j] = k++;
            tmp.emplace_back(j);
        }
        for (auto x : tmp) {
            sort(E[x].begin(), E[x].end(), [&](ll i, ll j) {
                return (vis[i] - vis[x] + k) % k < (vis[j] - vis[x] + k) % k;
            });
        }
    }
    vector<ll> cur(n);
    cur.assign(n, 0);
    vector<pair<ll, ll>> ans;
    auto check = [&](auto self, auto x) {
        if (cur[x] == E[x].size()) {
            return;
        }
        auto y = E[x][cur[x]];
        if (E[y][cur[y]] != x) {
            return;
        }
        cout << mp[{x, y}] << " ";
        ans.emplace_back(x, y);
        cur[x]++, cur[y]++;
        self(self, x);
        self(self, y);
    };
    for (ll i = 0; i < n; ++i) {
        check(check, i);
    }
    cout << "\n";
    for (auto &[l, r] : ans) {
        swap(a[l], a[r]);
    }
    assert(is_sorted(a.begin(), a.end()));
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