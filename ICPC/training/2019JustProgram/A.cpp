#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
string s;
vector<vector<pair<ll, ll>>> E;
vector<array<ll, 3>> edges;
namespace Tarjan {
ll n, dfs_clock;
vector<ll> low, dfn, iscut, pa;
vector<bool> isbridge;
auto dfs(ll u, ll fa) -> void {
    pa[u] = fa;
    low[u] = dfn[u] = ++dfs_clock;
    for (auto &[v, cst] : E[u]) {
        if (!dfn[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]) {
                isbridge[v] = true;
                cst = 0;
            }
        } else if (dfn[v] < dfn[u] && v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
}
auto tarjan(ll _n) {
    n = _n;
    low.assign(n, 0);
    dfn.assign(n, 0);
    iscut.assign(n, 0);
    pa.assign(n, 0);
    isbridge.assign(n, false);
    dfs_clock = 0;
    for (ll i = 0; i < n; ++i) {
        if (!dfn[i]) {
            dfs(i, -1);
        }
    }
    for (auto &[u, v, w] : edges) {
        if (pa[u] == v && !isbridge[u]) {
            w = 0;
        }
        if (pa[v] == u && !isbridge[v]) {
            w = 0;
        }
    }
    E.assign(n, vector<pair<ll, ll>>());
}
}; // namespace Tarjan

namespace atcoder {

// Implement (union by size) + (path compression)
// Reference:
// Zvi Galil and Giuseppe F. Italiano,
// Data structures and algorithms for disjoint set union problems
struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y)
            return x;
        if (-parent_or_size[x] < -parent_or_size[y])
            std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0)
            return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(std::remove_if(
                         result.begin(), result.end(),
                         [&](const std::vector<int> &v) { return v.empty(); }),
                     result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

} // namespace atcoder
namespace dp {
vector<ll> vis, H, A;
ll dfs(ll u, ll fa) {
    if (s[u] == 'H') {
        H[u]++;
    } else if (s[u] == 'A') {
        A[u]++;
    }
    vis[u] = 1;
    ll tmp = 0;
    for (auto [v, w] : E[u]) {
        if (v == fa)
            continue;
        tmp += dfs(v, u);
        H[u] += H[v];
        A[u] += A[v];
        tmp += (H[v] + A[v]) * w;
        // cout << u << " " << v << " " << w << "\n";
        auto cnt = min(H[u], A[u]);
        H[u] -= cnt;
        A[u] -= cnt;
    }
    // cout << u << " " << tmp << "\n";
    assert(A[u] == 0 || H[u] == 0);
    return tmp;
}
auto dp() {
    vis.assign(n, 0);
    H.assign(n, 0);
    A.assign(n, 0);
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (!vis[i]) {
            ans += dfs(i, -1);
        }
    }
    return ans;
}
}; // namespace dp
auto solve() {
    cin >> n >> m >> s;
    E.assign(n, vector<pair<ll, ll>>());
    edges.resize(m);
    for (ll i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        E[u].emplace_back(v, w);
        E[v].emplace_back(u, w);
        edges[i] = {u, v, w};
    }
    Tarjan::tarjan(n);
    atcoder::dsu DSU(n);
    sort(edges.begin(), edges.end(),
         [&](auto l, auto r) { return l[2] < r[2]; });
    for (auto [u, v, w] : edges) {
        if (DSU.same(u, v)) {
            continue;
        } else {
            DSU.merge(u, v);
            E[u].emplace_back(v, w);
            E[v].emplace_back(u, w);
        }
    }
    cout << dp::dp() << "\n";
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