#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    - @implementation @upsolve @geometry
    - obviously you need to make a graph out of connections.
    - n polygon always have n - 2 shape, claim. forms a tree
    - claim. we can arbitrary start at any outedge of any "exterior polygon",
   then dfs in order of any cyclic shift of "clockwise" lol
        - that is too hard to write, and I can't prove it's correct.

    - %% after editorial %%:
        - for the [1] order of the cuts (triangles), we build dual graph of the
   "mesh" and topological sort it.
        - for the [2] exterior vertice order,
            - either you can derive from [1], by reverse the process and
   maintain a linked list; [editorial solution]
            - or you can notice you just need to dfs over G, where G is the new
   graph only consists of exterior edges. [wzy's solution]
*/

const ll sz = 100000;
vector<ll> GOut[sz];
set<ll> GDual[sz];
vector<vector<ll>> triangles;
map<pair<ll, ll>, vector<ll>> edges;
bool vis[sz];

void outputVertices(ll o) {
    vis[o] = true;
    cout << o + 1 << " ";
    for (auto e : GOut[o])
        if (!vis[e])
            outputVertices(e);
}

pair<ll, ll> normedPair(const ll &u, const ll &v) {
    if (u <= v)
        return {u, v};
    else
        return {v, u};
}

void solve() {
    ll n;
    cin >> n;
    edges.clear();
    triangles.clear();
    triangles.resize(n - 2, vector<ll>(3));
    for (ll i = 0; i <= n - 1; i++)
        GOut[i].clear(), GDual[i].clear(), vis[i] = false;
    for (ll i = 0; i <= n - 3; i++)
        for (ll j = 0; j <= 2; j++)
            cin >> triangles[i][j], triangles[i][j]--;

    for (ll i = 0; i <= n - 3; i++)
        for (ll u = 0; u <= 2; u++)
            for (ll v = u + 1; v <= 2; v++)
                edges[normedPair(triangles[i][u], triangles[i][v])]
                    .emplace_back(i);

    for (auto [u, v] : edges) {
        assert(v.size() <= 2);
        if (v.size() == 2)
            GDual[v[0]].emplace(v[1]), GDual[v[1]].emplace(v[0]);
        else
            GOut[u.first].emplace_back(u.second),
                GOut[u.second].emplace_back(u.first);
    }

    outputVertices(1);
    cout << endl;

    for (ll i = 0; i <= n - 3; i++)
        vis[i] = false;
    queue<ll> q;
    for (ll i = 0; i <= n - 3; i++)
        if (GDual[i].size() <= 1)
            q.push(i), vis[i] = true;
    while (!q.empty()) {
        auto tf = q.front();
        q.pop();
        for (auto e : GDual[tf]) {
            GDual[e].erase(tf);
            if (GDual[e].size() <= 1 && !vis[e])
                q.push(e),
                    vis[e] = true; // could be that it's == 0, in which case is
                                   // last piece, since after each cut, the rest
                                   // is still connected.
        }
        GDual[tf].clear();
        cout << tf + 1 << " ";
    }
    cout << endl;
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
