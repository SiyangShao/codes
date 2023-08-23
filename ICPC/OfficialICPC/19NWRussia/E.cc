#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(ll i=(a); i<=(b); i++)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)
vector<ll> g[200005];
ll depth[200005];
ll followCnt[200005];

void solve(){
    ll n, m; cin >> n >> m;
    vector<vector<ll>> layers;
    FOR(i, 1, n - 1) {
        ll u, v; cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    FOR(i, 1, m) {
        ll t; cin >> t;
        vector<ll> curr = {t};
        layers.emplace_back(curr);
        depth[t] = 1, followCnt[t] = 1;
    }

    if (m == 1) {
        cout << "YES\n1" << endl;
        return;
    }

    ll nextDepth = 2;
    while (true) {
        vector<ll> ans;
        vector<vector<ll>> newLayers;
        bool hasNonEmpty = false;
        for (auto& vec: layers) {
            // expand vec
            vector<ll> tmp;
            for (auto e: vec) for (auto nVertice: g[e]) {
                if (depth[nVertice] == 0) {
                    tmp.emplace_back(nVertice);
                    depth[nVertice] = nextDepth;
                    followCnt[nVertice] = followCnt[e];
                } else if (depth[nVertice] == nextDepth) {
                    followCnt[nVertice] += followCnt[e];
                }
            }
            if (!tmp.empty()) newLayers.emplace_back(tmp), hasNonEmpty = true;
        }

        if (!hasNonEmpty) {
            break;
        }

        layers = std::move(newLayers);

        // check answer
        unordered_map<ll, ll> f;
        for (auto t: layers) for (auto e: t) f[e] += followCnt[e];
        for (auto [u, v]: f) if (v == m) {
            cout << "YES" << endl;
            cout << u << endl;
            return;
        }

        
        nextDepth++;
    }

    cout << "NO\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}