#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 1e6 + 1;
bitset<N> vis;
auto solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<vector<ll>> E(n);
    for (ll i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v), E[v].emplace_back(u);
    }
    vector<ll> x(q);
    vis[0] = true;
    for (auto &i : x) {
        cin >> i;
        vis = vis | (vis << i);
    }
    set<ll> st;
    for (ll i = 1; i < N; ++i) {
        if (vis[i]) {
            st.emplace(i);
        }
    }
    bool flag = false;
    function<void(int, int)> dfs = [&](int u, int fa) {
        ll mx = 0;
        for (auto v : E[u]) {
            if (v == fa)
                continue;
            dfs(v, u);
            mx = max(mx, a[v] - a[u]);
        }
        if (mx) {
            auto pos = st.lower_bound(mx);
            if (pos == st.end()) {
                flag = true;
            } else {
                a[u] += *pos;
            }
        }
    };
    dfs(0, -1);
    if (flag) {
        cout << "-1\n";
    } else {
        ll ans = 0;
        for (auto i : a) {
            ans += i;
        }
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