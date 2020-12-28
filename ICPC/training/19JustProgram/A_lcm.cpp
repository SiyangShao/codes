#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll sz = 100000;
set<pair<ll, ll>> g[sz];
vector<pair<ll, ll>> ng[sz];
ll nA[sz], nH[sz];

ll tIn[sz], low[sz];
bool vis[sz];
ll timer;

vector<ll> currBridgeNodes;
void contrib(ll o, ll trueFather) {
    if (ng[o].size())
        currBridgeNodes.push_back(o);
    vis[o] = true;
    if (o != trueFather)
        nA[trueFather] += nA[o], nH[trueFather] += nH[o];
    for (auto [e, w] : g[o])
        if (!vis[e])
            contrib(e, trueFather);
}

void findBridge(ll o, ll p = -1) {
    vis[o] = true;
    tIn[o] = low[o] = timer++;
    for (auto [e, w] : g[o]) {
        // if (e == p)
        //     continue;
        // if (vis[e])
        //     low[o] = min(low[o], tIn[e]);
        // else {
        //     findBridge(e, o), low[o] = min(low[o], low[e]);
        //     if (low[e] > tIn[o])
        //         ng[e].emplace_back(o, w), ng[o].emplace_back(e, w);
        // }
        if (!vis[e]) {
            findBridge(e, o);
            low[o] = min(low[o], low[e]);
            if (low[e] > tIn[o]) {
                ng[e].emplace_back(o, w), ng[o].emplace_back(e, w);
            }
        } else if (tIn[e] < tIn[o] && e != p) {
            low[o] = min(low[o], tIn[e]);
        }
    }
}
vector<ll> vvvis;
ll findAnswer(ll o, ll p = -1) {
    ll ans = 0;
    vvvis[o] = 1;
    for (auto [e, w] : ng[o])
        if (e != p) {
            ans += findAnswer(e, o);
            ans += nA[e] * w + nH[e] * w;
            nA[o] += nA[e], nH[o] += nH[e];
        }
    ll m = min(nA[o], nH[o]);
    nA[o] -= m, nH[o] -= m;
    return ans;
}

void solve() {
    ll n, b;
    cin >> n >> b;
    vvvis.assign(n, 0);
    for (ll i = 0; i < n; i++)
        g[i].clear(), ng[i].clear(), nA[i] = nH[i] = vis[i] = 0,
                                     tIn[i] = low[i] = -1;
    timer = 0;
    string s;
    cin >> s;
    for (ll i = 0; i < n; i++)
        nA[i] = (s[i] == 'A'), nH[i] = (s[i] == 'H');
    for (ll i = 0; i < b; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].emplace(v, w), g[v].emplace(u, w);
    }

    // 1. find wand applicable and merge them
    for (ll i = 0; i < n; i++)
        if (!vis[i])
            findBridge(i, -1);

    for (ll i = 0; i < n; i++)
        for (auto [e, w] : ng[i])
            g[i].erase(make_pair(e, w)); // make G a forest
    for (ll i = 0; i < n; i++)
        vis[i] = false;

    ll anyBP = -1;
    vector<pair<ll, ll>> newEdges;
    for (ll i = 0; i < n; i++) { // contributionally move all stuff of this
                                 // component to someone, then add edge lolz
        if (ng[i].size())
            anyBP = i;
        currBridgeNodes.clear();
        if (ng[i].size() && !vis[i])
            contrib(i, i);
        for (ll t = 0; t < (signed)currBridgeNodes.size() - 1; t++)
            newEdges.emplace_back(currBridgeNodes[t], currBridgeNodes[t + 1]);
    }
    for (auto [u, v] : newEdges)
        ng[u].emplace_back(v, 0), ng[v].emplace_back(u, 0);
    // 2. reduced to simple on tree DP
    ll ans = 0;
    for (ll i = 0; i < n; ++i) {
        if (!vvvis[i]) {
            ans += findAnswer(i);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}