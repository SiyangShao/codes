#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll mod = 1e9 + 7;
constexpr ll INF = INT_MAX;
ll s, t;
vector<ll> us;
vector<ll> dist;
vector<ll> dp[2];
ll bfs(vector<vector<ll>> &g) {
    queue<tuple<ll, ll, ll>> q;
    q.push({s, 0, 0}); //[v, dist, count]
    ll ans = 0, mnd = INF;
    us[s] = 1;
    dp[0][s] = 1;
    dist[s] = 0;
    while (!q.empty()) {
        auto [v, d, x] = q.front();
        q.pop();
        // cerr << v << ' ' << d << ' ' << dp[x][v] << endl;
        if (v == t) {
            if (mnd == INF) {
                mnd = d;
            }
            ans += dp[x][v];
            ans %= mod;
        }
        if (d == mnd + 1)
            continue;
        for (int to : g[v])
            if (d <= dist[to]) {
                dist[to] = min(dist[to], d + 1);
                dp[d - dist[to] + 1][to] += dp[x][v];
                dp[d - dist[to] + 1][to] %= mod;
                // cerr << "TO: " <<  to << ' ' << dist[to] << ' ' << d << endl;
                if (us[to] == 0 || (us[to] == 1 && dist[to] == d))
                    q.push({to, d + 1, us[to]++});
            }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    cin >> s >> t;
    us.resize(n + 1);
    dp[0].resize(n + 1);
    dp[1].resize(n + 1);
    dist.resize(n + 1);
    for (int i = 0; i <= n; ++i) {
        us[i] = dp[0][i] = dp[1][i] = 0;
        dist[i] = INF;
    }

    vector<vector<ll>> g(n + 1);
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    cout << bfs(g) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int _ = 1;
    cin >> _;
    while (_--) {
        solve();
    }
}