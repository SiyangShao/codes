#include <bits/stdc++.h>
using namespace std;
template <class Cap> struct mf_graph {
    // maxflow_graph
    using pii = pair<int, int>;
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
        _edge(int _to, int _rev, Cap _cap) : to(_to), rev(_rev), cap(_cap) {}
    };
    vector<pii> pos;
    vector<vector<_edge>> g;
    struct edge {
        int from, to;
        Cap cap, flow;
        edge(int _from, int _to, Cap _cap, Cap _flow)
            : from(_from), to(_to), cap(_cap), flow(_flow) {}
    };
    mf_graph() : _n(0){};
    explicit mf_graph(int n) : _n(n), g(n){};
    int add_edge(int from, int to, Cap cap) {
        int m = pos.size();
        pos.emplace_back(from, g[from].size());
        int from_id = g[from].size();
        int to_id = g[to].size();
        if (from == to) {
            to_id++;
        }
        g[from].emplace_back(to, to_id, cap);
        g[to].emplace_back(from, from_id, 0);
        return m;
    }
    Cap flow(int s, int t) { return flow(s, t, numeric_limits<Cap>::max()); }
    Cap flow(int s, int t, Cap flow_limit) {
        vector<int> level(_n), iter(_n);
        queue<int> que;
        auto bfs = [&]() {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que = {};
            que.emplace(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0)
                        continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t)
                        return;
                    que.push(e.to);
                }
            }
        };
        function<Cap(int, Cap)> dfs = [&](int v, Cap up) {
            if (v == s)
                return up;
            Cap res = 0;
            int level_v = level[v];
            for (int &i = iter[v]; i < int(g[v].size()); ++i) {
                _edge &e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) {
                    continue;
                }
                Cap d = dfs(e.to, min(up - res, g[e.to][e.rev].cap));
                if (d <= 0)
                    continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up)
                    return res;
            }
            level[v] = _n;
            return res;
        };
        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1)
                break;
            fill(iter.begin(), iter.end(), 0);
            auto f = dfs(t, flow_limit - flow);
            if (!f)
                break;
            flow += f;
        }
        return flow;
    }
    auto get_edge(int i) {
        int m = pos.size();
        auto e = g[pos[i].first][pos[i].second];
        auto re = g[e.to][e.rev];
        return edge{pos[i].first, e.to, e.cap + re.cap, re.cap};
    }
    // unnecessary part
    auto edges() {
        int m = pos.size();
        vector<edge> result;
        for (int i = 0; i < m; ++i) {
            result.emplace_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow = 0) {
        int m = int(pos.size());
        auto &e = g[pos[i].first][pos[i].second];
        auto &re = g[e.to][e.rev];
        e.cap = new_cap - new_flow;
        re.cap = new_flow;
    }
    auto min_cut(int s) {
        vector<int> visited(_n, 0);
        queue<int> que = {};
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = 1;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = 1;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }
};
using ll = long long;

auto solve() {
    ll m, n;
    cin >> m >> n;
    vector<ll> b(m), r(n);
    map<ll, ll> mp;
    mp.clear();
    ll siz = 0;
    for (auto &i : b) {
        cin >> i;
    }
    for (auto &i : r) {
        cin >> i;
    }
    vector<vector<ll>> B(m), R(n);
    for (ll k = 0; k < n; ++k) {
        auto tmp = r[k];
        for (ll i = 2; i * i <= tmp; ++i) {
            if (tmp % i == 0) {
                if (mp.find(i) == mp.end()) {
                    mp[i] = ++siz;
                }
                while (tmp % i == 0) {
                    tmp /= i;
                }
                R[k].emplace_back(mp[i]);
            }
        }
        if (tmp != 1) {
            if (mp.find(tmp) == mp.end()) {
                mp[tmp] = ++siz;
            }
            R[k].emplace_back(mp[tmp]);
        }
    }
    for (ll k = 0; k < m; ++k) {
        auto tmp = b[k];
        for (ll i = 2; i * i <= tmp; ++i) {
            if (tmp % i == 0) {
                if (mp.find(i) == mp.end()) {
                    mp[i] = ++siz;
                }
                while (tmp % i == 0) {
                    tmp /= i;
                }
                B[k].emplace_back(mp[i]);
            }
        }
        if (tmp != 1) {
            if (mp.find(tmp) == mp.end()) {
                mp[tmp] = ++siz;
            }
            B[k].emplace_back(mp[tmp]);
        }
    }
    mf_graph<ll> G(n + m + siz + 2);
    for (ll i = 0; i < m; ++i) {
        G.add_edge(0, i + 1, 1);
        for (auto j : B[i]) {
            G.add_edge(i + 1, m + j, 1);
        }
    }
    for (ll i = 0; i < n; ++i) {
        G.add_edge(m + siz + i + 1, m + siz + n + 1, 1);
        for (auto j : R[i]) {
            G.add_edge(m + j, m + siz + i + 1, 1);
        }
    }
    cout << G.flow(0, m + siz + n + 1) << "\n";
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