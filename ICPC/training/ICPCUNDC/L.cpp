#include<bits/stdc++.h>
using namespace std;
using ll = long long;
array<vector<ll>, 100002> g;
array<ll, 100002> a;
vector<ll> possible;
bool gg = false;

void dfs(ll o, ll p = -1) {
    ll mxSon = 0;
    for (auto e: g[o]) if (e != p) dfs(e, o), mxSon = max(mxSon, a[e]);
    ll diff = max(0ll, mxSon - a[o]);
    if (diff) {
        auto p = lower_bound(possible.begin(), possible.end(), diff);
        if (p != possible.end()) a[o] += *p;
        else gg = true;
    }
}

int main() {
    ll n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i < n; ++i) {
        ll u, v; cin >> u >> v;
        g[u].emplace_back(v), g[v].emplace_back(u);
    }
    deque<bool> sPrev(), sCurr;
    for (ll tq = 1; tq <= q; ++tq) {
        sCurr.clear();
        ll x; cin >> x;
        sCurr.emplace(x);
        for (auto e: sPrev) sCurr.emplace(e);
        for (auto e: sPrev) sCurr.emplace(x + e);
        sPrev = sCurr;
    }
    for (auto e: sCurr) possible.emplace_back(e);
    sort(possible.begin(), possible.end());

    dfs(1);
    
    if (gg) cout << -1 << endl;
    else {
        ll ans = 0;
        for (int i = 1; i <= n; ++i) ans += a[i];
        cout << ans << endl;
    }

}