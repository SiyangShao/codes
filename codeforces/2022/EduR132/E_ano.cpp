#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll N = 2e5 + 7;
auto solve() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (auto &i : a) {
        cin >> i;
    }
    vector<vector<ll>> E(n);
    for (ll i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        u--, v--;
        E[u].emplace_back(v);
        E[v].emplace_back(u);
    }
    vector<ll> fa(n), dep(n), siz(n), hson(n, -1), L(n), R(n), Node(n);
    ll tmp = 0;
    function<ll(ll)> tree_build = [&](ll u) {
        siz[u] = 1;
        L[u] = tmp;
        Node[tmp] = u;
        tmp++;
        for (auto v : E[u]) {
            if (v == fa[u])
                continue;
            fa[v] = u;
            dep[v] = dep[u] + 1;
            siz[u] += tree_build(v);
            if (hson[u] == -1 || siz[v] > siz[hson[u]]) {
                hson[u] = v;
            }
        }
        R[u] = tmp;
        return siz[u];
    };
    tree_build(0);
    vector<ll> dp(n);
    set<ll> st;
    bitset<N> change;
    function<void(ll, ll)> dfs = [&](ll u, ll fa) {
        dp[u] = a[u];
        if (fa != u) {
            dp[u] ^= dp[fa];
        }
        for (auto v : E[u]) {
            if (v != fa && v != hson[u]) {
                st.clear();
                dfs(v, u);
            }
        }
        st.clear();
        if (hson[u] != -1) {
            dfs(hson[u], u);
        }
        bool flag = false;
        ll bs = a[u], ano = a[u] ^ dp[u];
        if (st.contains(ano)) {
            flag = true;
        }
        function<bool(ll, ll)> check = [&](ll u, ll fa) {
            if (st.contains(bs ^ dp[u]) || dp[u] == ano) {
                return true;
            }
            bool ans = false;
            for (auto v : E[u]) {
                if (v == fa || change[v])
                    continue;
                ans = ans || check(v, u);
            }
            return ans;
        };
        function<void(ll, ll)> upd = [&](ll u, ll fa) {
            st.insert(dp[u]);
            for (auto v : E[u]) {
                if (change[v] || v == fa)
                    continue;
                upd(v, u);
            }
        };
        if (!flag)
            for (auto v : E[u]) {
                if (v == fa || change[v] || v == hson[u])
                    continue;
                flag = flag || check(v, u);
                upd(v, u);
            }
        change[u] = flag;
        if (!flag) {
            st.insert(dp[u]);
        } else {
            st.clear();
        }
    };
    dfs(0, 0);
    cout << change.count() << "\n";
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