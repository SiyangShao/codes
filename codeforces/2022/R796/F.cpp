#include <bits/stdc++.h>
using namespace std;
using ll = long long;
auto solve() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a, b;
    a.assign(n + 1, 0), b.assign(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> b[i];
    }
    vector<ll> id(n + 1), deg(m);
    deg.assign(m, 2);
    iota(id.begin(), id.end(), 0);
    set<ll> st(id.begin(), id.end());
    vector<vector<ll>> E(n + 1);
    E.assign(n + 1, vector<ll>());
    vector<pair<ll, ll>> p(m);
    ll tmp = 0;
    for (auto &[l, r] : p) {
        cin >> l >> r;
        E[l - 1].emplace_back(tmp);
        E[r].emplace_back(tmp);
        tmp++;
    }
    queue<ll> Q;
    Q.push(0);
    st.erase(0);
    for (ll i = 1; i <= n; ++i) {
        a[i] -= b[i];
        a[i] += a[i - 1];
        if (a[i] == 0) {
            Q.push(i);
            st.erase(i);
        }
    }
    while (!Q.empty()) {
        auto u = Q.front();
        Q.pop();
        for (auto v : E[u]) {
            deg[v]--;
            if (!deg[v]) {
                auto [l, r] = p[v];
                auto lt = st.lower_bound(l), rt = st.upper_bound(r);
                for (auto i = lt; i != rt; ++i) {
                    Q.push(*i);
                }
                st.erase(lt, rt);
            }
        }
    }
    if (st.empty()) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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