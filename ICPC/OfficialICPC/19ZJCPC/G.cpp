#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr double eps = 1e-9;
constexpr double INF = 1e9 + 7;
auto solve() {
    ll n;
    cin >> n;
    vector<pair<ll, ll>> p(n);
    for (auto &[x, y] : p) {
        cin >> x >> y;
    }
    pair<ll, ll> s, t;
    cin >> s.first >> s.second >> t.first >> t.second;
    double v_1, v_2;
    cin >> v_1 >> v_2;
    auto len_edge = [&](pair<ll, ll> x, pair<ll, ll> y) {
        double a = sqrt((y.first - x.first) * (y.first - x.first) +
                        (y.second - x.second) * (y.second - x.second));
        return a;
    };
    auto cal_edge = [&](double x) {
        double cnt = (x * 1.0 / v_2);
        if (x <= 3 * v_2) {
            return cnt;
        }
        x -= 3 * v_2;
        return double(3.0 + (x * 1.0) / v_1);
    };
    vector<vector<pair<double, ll>>> E(n + 2);
    for (ll i = 0; i < n; ++i) {
        E[0].emplace_back(len_edge(s, p[i]) / v_1, i + 1);
    }
    E[0].emplace_back(len_edge(s, t) / v_1, n + 1);
    for (ll i = 0; i < n; ++i) {
        E[i + 1].emplace_back(cal_edge(len_edge(p[i], t)), n + 1);
    }
    for (ll i = 0; i < n; ++i) {
        for (ll j = 0; j < n; ++j) {
            if (i == j)
                continue;
            E[i + 1].emplace_back(cal_edge(len_edge(p[i], p[j])), j + 1);
        }
    }
    vector<double> dis(n + 2, INF);
    dis.assign(n + 2, INF);
    vector<ll> vis(n + 2, 0);
    vis.assign(n + 2, 0);
    dis[0] = 0;
    priority_queue<pair<double, ll>, vector<pair<double, ll>>, greater<>> Q;
    Q.emplace(dis[0], 0);
    while (!Q.empty()) {
        auto [d, u] = Q.top();
        Q.pop();
        if (vis[u] == 1)
            continue;
        vis[u] = 1;
        for (auto [w, v] : E[u]) {
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                Q.emplace(dis[v], v);
            }
        }
    }

    cout << setprecision(14) << dis[n + 1] << "\n";
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