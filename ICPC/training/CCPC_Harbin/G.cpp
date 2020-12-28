#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define eb emplace_back
#define all0(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define ROF(i, a, b) for(ll i=(a); i>=(b); i--)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
vector<pair<ll, ld>> g[100005]; // ni, nd // should be ll
vector<pair<ll, ll>> bikes; // pos, P(fail)

vl dists[19];
ll t, r, n, m;
ld dp[262146][19]; // dp[S][p] means the minimum expected cost to arrive at school by visiting exactly bikes in S, when you starts walking at p.


ll popcnt[262146];
void dijkstra(ll start, ll id) {
    dists[id].resize(n + 2);
    FOR(i, 1, n) if (i != start) dists[id][i] = LLONG_MAX;
    set<pair<ll, ll>> s; s.emplace(0, start);
    while (!s.empty()) {
        auto [td, ti] = *s.begin(); s.erase(s.begin());
        for (const auto& [ei, ed]: g[ti]) if (td + ed < dists[id][ei]) {
            s.erase({dists[id][ei], ei});
            dists[id][ei] = td + ed;
            s.insert({dists[id][ei], ei});
        }
    }
}

inline ll highbit(const ll& x) {
    return 64 - __builtin_clzll(x);
}

void solve(){
    // 1. input
    cin >> t >> r >> n >> m; 
    FOR(i, 1, m) {
        ll u, v, d; cin >> u >> v >> d;
        g[u].eb(v, d), g[v].eb(u, d);
    }
    ll nBike; cin >> nBike; bikes.resize(nBike + 1);
    FOR(tb, 1, nBike) cin >> bikes[tb].first >> bikes[tb].second;

    // 2. preprocess distance pairs
    dijkstra(1, 0);
    FOR(i, 1, nBike) dijkstra(bikes[i].first, i);

    // 3. preprocess order for DP
    ll maxComb = (1ll << nBike) - 1;
    FOR(i, 1, n) popcnt[i] = __builtin_popcountll(i);
    vl a(maxComb + 1); FOR(i, 0, maxComb) a[i] = i;
    sort(all0(a), [](const auto& u, const auto& v) { return popcnt[u] < popcnt[v]; });

    // 4. dp
    // FOR(i, 0, maxComb) FOR(j, 0, nBike) dp[i][j] = LLONG_MAX; // hope suffice
    for (const auto& S: a) FOR(p, 0, nBike) if (p == 0 || !(S & (1ll << (p - 1)))) { // current position cannot inside S
        dp[S][p] = (ld)dists[p][n] / t;
        FOR(tg, 1, nBike) if ((1ll << (tg - 1)) & S) { // for all valid goals
            ld costToG = (ld)dists[p][bikes[tg].first] / t;
            ld costNice = (ld)dists[tg][n] / r * (100 - bikes[tg].second) / (ld)100.0; // he just went to it
            ld E = costToG + costNice + bikes[tg].second / (ld)100.0 * dp[S ^ (1ll << (tg - 1))][tg];
            chkmin(dp[S][p], E);
        }
    }
    // 5. output
    ld ans = LLONG_MAX; // hope suffice
    FOR(i, 0, maxComb) chkmin(ans, dp[i][0]);
    if (dists[0][n] == LLONG_MAX) cout << -1 << endl;
    else cout << fixed << setprecision(15) << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
