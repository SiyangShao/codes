#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll inf = 1e16;
template <class Cap> struct dinic {
    struct edge {
        int from, to;
        Cap w;
        edge(int _f, int _t, Cap _w) : from(_f), to(_t), w(_w){};
    };
    vector<vector<int>> E;
    vector<edge> edg;
    vector<int> d, q;
    int n;
    dinic(int _n) : n(_n), E(_n), d(_n), q(_n) {}
    void addEdge(int u, int v, Cap w) {
        int id = edg.size();
        edg.emplace_back(u, v, w), edg.emplace_back(v, u, 0);
        E[u].emplace_back(id), E[v].emplace_back(id ^ 1);
    }
    auto dfs(int u, int t, Cap flow) {
        if (u == t)
            return flow;
        Cap sum = 0;
        for (auto id : E[u]) {
            if (edg[id].w != 0 && d[edg[id].to] == d[u] + 1) {
                auto tmp = dfs(edg[id].to, t, min(flow, edg[id].w));
                edg[id].w -= tmp, edg[id ^ 1].w += tmp, sum += tmp, flow -= tmp;
            }
        }
        if (sum == 0)
            d[u] = 0;
        return sum;
    }
    bool level(int s, int t) {
        fill(d.begin(), d.end(), 0);
        int l = 0, r = 0;
        d[s] = 1, q[r++] = s;
        while (l < r) {
            int u = q[l++];
            if (u == t)
                return true;
            for (auto id : E[u]) {
                auto v = edg[id].to;
                if (d[v] == 0 && edg[id].w != 0)
                    q[r++] = v, d[v] = d[u] + 1;
            }
        }
        return false;
    }
    auto solve(int s, int t) {
        Cap ans = 0;
        while (level(s, t))
            ans += dfs(s, t, inf);
        return ans;
    }
};
auto solve() {
    int n, m;
    cin >> n >> m;
    dinic<ll> G(n * 2);
    vector<vector<pair<ll, ll>>> E(n);
    for (int i = 0; i < m; ++i) {
        ll a, b, d;
        cin >> a >> b >> d;
        a--, b--;
        E[a].emplace_back(b, d);
        E[b].emplace_back(a, d);
    }
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> Q;
    vector<ll> dis(n, inf), vis(n, 0);
    dis[0] = 0;
    Q.emplace(0, 0);
    while (!Q.empty()) {
        auto [_, u] = Q.top();
        Q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        for (auto [v, d] : E[u]) {
            if (dis[v] > dis[u] + d) {
                dis[v] = dis[u] + d;
                Q.emplace(dis[v], v);
            }
        }
    }
    for (ll i = 0; i < n; ++i) {
        for (auto [v, d] : E[i]) {
            if (dis[v] == dis[i] + d) {
                G.addEdge(i, v + n, inf);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        G.addEdge(i + n, i, c);
    }
    cout << G.solve(0, n + n - 1) << "\n";
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