#include <bits/stdc++.h>
using namespace std;
// O(n^3), only wokrs on *bipartite graph maximum perfect matching*
// can be applied on negative one
template <class Cap> struct Hungarain {
    int n;
    vector<int> match_x, match_y, pre;
    vector<bool> vis_x, vis_y;
    vector<vector<Cap>> g;
    vector<Cap> slack;
    vector<Cap> lx, ly;
    Cap inf, res;
    queue<int> q;
    int org_n, org_m;
    Hungarain(int _n, int _m) {
        org_n = _n, org_m = _m;
        n = max(_n, _m);
        inf = numeric_limits<Cap>::max();
        res = 0;
        g = vector<vector<Cap>>(n, vector<Cap>(n, -inf));
        match_x = match_y = vector<int>(n, -1);
        pre = vector<int>(n);
        vis_x = vis_y = vector<bool>(n);
        lx = vector<Cap>(n, -inf);
        ly = vector<Cap>(n);
        slack = vector<Cap>(n);
    };
    void addEdge(int u, int v, int w) { g[u][v] = w; }
    bool check(int v) {
        vis_y[v] = true;
        if (match_y[v] != -1) {
            q.push(match_y[v]);
            vis_x[match_y[v]] = true;
            return false;
        }
        while (v != -1) {
            match_y[v] = pre[v];
            swap(v, match_x[pre[v]]);
        }
        return true;
    }
    void bfs(int i) {
        while (!q.empty()) {
            q.pop();
        }
        q.push(i);
        vis_x[i] = true;
        while (true) {
            while (!q.empty()) {
                auto u = q.front();
                q.pop();
                for (int v = 0; v < n; ++v) {
                    if (!vis_y[v]) {
                        auto delta = lx[u] + ly[v] - g[u][v];
                        if (slack[v] >= delta) {
                            pre[v] = u;
                            if (delta) {
                                slack[v] = delta;
                            } else if (check(v)) {
                                return;
                            }
                        }
                    }
                }
            }
            auto a = inf;
            for (int j = 0; j < n; ++j) {
                if (!vis_y[j]) {
                    a = min(a, slack[j]);
                }
            }
            for (int j = 0; j < n; ++j) {
                if (vis_x[j]) {
                    lx[j] -= a;
                }
                if (vis_y[j]) {
                    ly[j] += a;
                } else {
                    slack[j] -= a;
                }
            }
            for (int j = 0; j < n; ++j) {
                if (!vis_y[j] && slack[j] == 0 && check(j)) {
                    return;
                }
            }
        }
    }
    void solve() {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                lx[i] = max(lx[i], g[i][j]);
            }
        }
        for (int i = 0; i < n; ++i) {
            fill(slack.begin(), slack.end(), inf);
            fill(vis_x.begin(), vis_x.end(), false);
            fill(vis_y.begin(), vis_y.end(), false);
            bfs(i);
        }
        // output
        for (int i = 0; i < n; ++i) {
            if (g[i][match_x[i]] > -inf) {
                // have edge
                res += g[i][match_x[i]];
            } else {
                // no match
                match_x[i] = -1;
            }
        }
        cout << -res << "\n";
    }
};
auto solve() {
    int n, m;
    cin >> n >> m;
    Hungarain<int> hun(n, n);
    vector<pair<int, int>> mp(m);
    for (auto &[x, y] : mp) {
        cin >> x >> y;
        x--, y--;
        hun.addEdge(x, y, -1);
    }
    hun.solve();
}
auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    // cin>>_;
    while (_--) {
        solve();
    }
}