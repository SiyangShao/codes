#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 998244353;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), _in(n, 0);
    for (auto &i : a) {
        cin >> i;
    }
    vector<vector<ll>> E(n);
    for (ll i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        _in[v]++;
    }
    function<bool()> bfs = [&]() {
        auto in = _in;
        vector<ll> b(n, 0);
        queue<ll> Q;
        for (int i = 0; i < n; ++i) {
            if (in[i] == 0) {
                Q.emplace(i);
            }
        }
        while (!Q.empty()) {
            auto u = Q.front();
            Q.pop();
            for (auto v : E[u]) {
                in[v]--;
                if (in[v] == 0) {
                    Q.emplace(v);
                }
                if (a[u]) {
                    b[v]++;
                }
            }
            if (a[u]) {
                a[u]--;
            }
            a[u] += b[u];
        }
        return *max_element(a.begin(), a.end()) == 0;
    };
    if (*max_element(a.begin(), a.end()) == 0) {
        cout << "0\n";
        return;
    }
    for (int i = 1; i <= n; ++i) {
        if (bfs()) {
            cout << i << "\n";
            return;
        }
    }
    queue<ll> Q;
    for (int i = 0; i < n; ++i) {
        if (_in[i] == 0) {
            Q.emplace(i);
        }
    }
    ll ans = 0;
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        if (E[u].empty()) {
            ans = a[u];
        }
        for (auto v : E[u]) {
            a[v] += a[u];
            a[v] %= MOD;
            _in[v]--;
            if (_in[v] == 0) {
                Q.emplace(v);
            }
        }
    }
    cout << (ans + n) % MOD << "\n";
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