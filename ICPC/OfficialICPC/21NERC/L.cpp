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

vl g[200005];
set<ll> vis;
#define ex(a, x) (a.find(x) != a.end())
ll tprevious[200005];
ll previous[200005]; // for all node, if exist prev
ll n, m, s; 
ll dfs(ll o) {
    for (auto e: g[o]) if (e != s) if (!ex(vis, e)) { // never go back to s
        tprevious[e] = o;
        vis.insert(e); // do not repeat 
        if (previous[e] != 0) { // arrivable by other supernode
            return e;
        } else {
            ll tval = dfs(e);
            if (tval) return tval;
        }
    }
    return 0;
}

void solve(){
    cin >> n >> m >> s;
    FOR(i, 1, m) {
        ll u, v; cin >> u >> v;
        g[u].eb(v);
    }
    for (auto tMega: g[s]) tprevious[tMega] = previous[tMega] = s; 
    for (auto tMega: g[s]) {
        vis.insert(tMega); // so that does not go back to tMega ... 
        ll e = dfs(tMega);
        if (e) {
            cout << "Possible" << endl;
            vl route1 = {e}, route2 = {e};
            while (route1.back() != s) route1.push_back(previous[route1.back()]);
            while (route2.back() != s) route2.push_back(tprevious[route2.back()]);
            reverse(all0(route1)), reverse(all0(route2));
            cout << route1.size() << endl;
            for (auto e: route1) cout << e << " ";
            cout << endl;
            cout << route2.size() << endl;
            for (auto e: route2) cout << e << " ";
            cout << endl;
            return;
        } else {
            for (const auto& e: vis) {
                if (!previous[e]) previous[e] = tprevious[e]; // should be always hold
                if (tprevious[e] != s) tprevious[e] = 0; // do not clear supernode themselves
            }
            vis.clear();
        }
    }
    cout << "Impossible" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
