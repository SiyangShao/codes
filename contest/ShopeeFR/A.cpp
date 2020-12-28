#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vl;
#define eb emplace_back
#define all0(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define ROF(i, a, b) for (ll i = (a); i >= (b); i--)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
// Shopee Xpress Delivery
ll a[1003][1003];
vector<pair<ll, ll>> g[1000006]; // dist, e
ll n, m;
ll from2d(ll x, ll y) { return (x - 1) * m + y; }
ll dist[1000006];
void solve() {
    cin >> n >> m;
    map<ll, vl> holes;
    FOR(i, 1, n) FOR(j, 1, m) {
        cin >> a[i][j];
        if (a[i][j])
            holes[a[i][j]].emplace_back(from2d(i, j));
    }
    FOR(i, 1, n) FOR(j, 1, m) {
        if (j != m) {
            ll n1 = from2d(i, j), n2 = from2d(i, j + 1);
            g[n1].emplace_back(1, n2), g[n2].emplace_back(1, n1);
        }
        if (i != n) {
            ll n1 = from2d(i, j), n2 = from2d(i + 1, j);
            g[n1].emplace_back(1, n2), g[n2].emplace_back(1, n1);
        }
    }
    for (const auto &[u, v] : holes) {
        for (auto t1 : v)
            for (auto t2 : v)
                if (t1 != t2)
                    g[t1].eb(0, t2), g[t2].eb(0, t1);
    }
    // dijkstra from 1 to goal
    ll goal = from2d(n, m);
    FOR(i, 2, goal) dist[i] = LLONG_MAX;
    set<pair<ll, ll>> s;
    s.emplace(0, 1);
    while (!s.empty()) {
        auto [tDist, tElem] = *s.begin();
        s.erase(s.begin());
        for (auto [ed, e] : g[tElem])
            if (dist[e] > tDist + ed) {
                s.erase({dist[e], e});
                dist[e] = tDist + ed;
                s.insert({dist[e], e});
            }
    }
    cout << dist[goal] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
