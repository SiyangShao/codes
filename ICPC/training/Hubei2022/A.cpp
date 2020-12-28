#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll INF = 1LL << 60;
auto solve() {
    ll n, m, k, t;
    cin >> n >> m >> k >> t;
    if (t == 0 || m < n - 1) {
        cout << "-1\n";
        return;
    }
    vector<vector<ll>> mp(n, vector<ll>(n));
    for (auto &i : mp) {
        i.assign(n, INF);
    }
    for (ll i = 0; i < n; ++i) {
        mp[i][i] = 0;
    }
    for (ll i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        mp[a][b] = min(mp[a][b], c);
        mp[b][a] = min(mp[b][a], c);
    }
    for (ll k = 0; k < n; ++k) {
        for (ll x = 0; x < n; ++x) {
            for (ll y = 0; y < n; ++y) {
                mp[x][y] = min(mp[x][y], mp[x][k] + mp[k][y]);
            }
        }
    }
    for (ll x = 0; x < n; ++x) {
        for (ll y = 0; y < n; ++y) {
            if (mp[x][y] >= INF) {
                cout << "-1\n";
                return;
            }
        }
    }
    vector<ll> pcr(k);
    for (auto &i : pcr) {
        cin >> i;
        i--;
    }
    ll contribution = 0;
    if (k != 1) {
        sort(pcr.begin(), pcr.end());
        vector<ll> fa(n);
        iota(fa.begin(), fa.end(), 0);
        auto find = [&](auto self, auto u) -> ll {
            if (u != fa[u]) {
                fa[u] = self(self, fa[u]);
            }
            return fa[u];
        };
        auto merge = [&](auto u, auto v) {
            u = find(find, u), v = find(find, v);
            fa[u] = v;
        };
        vector<vector<ll>> e;
        e.clear();
        for (ll i = 0; i < k; ++i) {
            for (ll j = 0; j < k; ++j) {
                if (i == j)
                    continue;
                e.push_back({mp[pcr[i]][pcr[j]], pcr[i], pcr[j]});
            }
        }
        sort(e.begin(), e.end(), [&](auto u, auto v) { return u[0] < v[0]; });
        for (auto &edge : e) {
            auto u = edge[1], v = edge[2];
            if (find(find, u) != find(find, v)) {
                merge(u, v);
                contribution = max(contribution, edge[0]);
            }
        }
        auto F = find(find, pcr[0]);
        for (auto &i : pcr) {
            if (F != find(find, i)) {
                cout << "-1\n";
                return;
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        ll len = INF;
        for (auto v : pcr) {
            len = min(len, mp[i][v]);
        }
        if (len >= INF) {
            cout << "-1\n";
            return;
        }
        contribution = max(contribution, len * 2);
    }
    if (contribution % t == 0) {
        cout << contribution / t;
    } else {
        cout << contribution / t + 1;
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