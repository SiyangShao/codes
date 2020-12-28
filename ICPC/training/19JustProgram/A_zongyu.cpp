#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef string str;
typedef vector<ll> vl;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector<ll>> vvl;
typedef vector<ii> vii;
typedef vector<vector<ii>> vvii;
typedef vector<iii> viii;
typedef vector<vector<iii>> vviii;
typedef vector<str> vs;
typedef vector<vector<str>> vvs;
typedef long double ld;

// typelower_bounddef priority_queue<long long> pq;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> pbds;
typedef set<int>::iterator sit;
typedef map<int, int>::iterator mit;
typedef vector<int>::iterator vit;

#define LSOne(S) ((S) & -(S))
#define elif else if
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define FOR(i, v) for (auto i : v)
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define rrep(i, a, b) for (int i = (a); i >= (b); i--)
#define repn(i, a, b) for (int i = (a); i <= (b); i++)
#define repin(i, a, b, x) for (int i = (a); i < (b); i += x)
#define repnin(i, a, b, x) for (int i = (a); i <= (b); i += x)
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define fbo find_by_order
#define ook order_of_key
#define ALL(v) v.begin(), v.end()
#define FILL(arr, x) memset(arr, x, sizeof arr);
// if else int i = (number <0) ? 1:0 -  if (number <0) i=1 else 0
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

vl dfs_num, dfs_low, dfs_parent, visited;
map<ii, int> mpp;
vvl graph;
vii tin;
int dfscnt = 0, dfsroot, root;
void bridge(int u) {
    dfs_num[u] = dfscnt++;
    dfs_low[u] = dfs_num[u];
    for (int v : graph[u]) {
        if (dfs_num[v] == -1) {
            dfs_parent[v] = u;
            if (u == dfsroot)
                ++root;

            bridge(v);

            if (dfs_low[v] > dfs_num[u]) {
                tin.pb(min(v, u), max(v, u));
                // cout << v +1 << " " << u +1 << "articulation\n";
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        } else if (v != dfs_parent[u]) {
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
        }
    }
}
vvii graph2;
vl nA, nH;

ll dfs(ll o, ll p = -1) {
    ll ans = 0;
    visited[o] = 1;
    for (auto [e, w] : graph2[o])
        if (e != p) {
            ans += dfs(e, o);
            ans += nA[e] * w + nH[e] * w;
            nA[o] += nA[e], nH[o] += nH[e];
        }
    ll m = min(nA[o], nH[o]);
    nA[o] -= m, nH[o] -= m;
    return ans;
}

void solve() {
    mpp.clear();
    tin.clear();
    dfs_num.clear();
    dfs_low.clear();
    dfs_parent.clear();
    visited.clear();
    graph.clear();
    dfscnt = 0;
    graph2.clear();
    nA.clear();
    nH.clear();
    int n, b;
    cin >> n >> b;
    str s;
    cin >> s;
    graph.assign(n + 1, vl());

    rep(i, 0, b) {
        int u, v, c;

        cin >> u >> v >> c;
        u--;
        v--;
        graph[u].pb(v);
        graph[v].pb(u);
        mpp[ii(min(u, v), max(u, v))] = c;
    }

    dfs_num.assign(n + 1, -1);
    visited.assign(n + 1, 0);
    dfs_low.assign(n + 1, 0);
    dfs_parent.assign(n + 1, -1);
    dfscnt = 0;
    for (int u = 0; u < n; u++) {
        if (dfs_num[u] == -1) {
            dfsroot = u;
            root = 0;
            bridge(u);
        }
    }
    map<int, int> lowton;
    int cnt = 0;

    graph2.assign(n + 1, vii());
    for (ii c : tin) {
        if (lowton.find(dfs_low[c.first]) == lowton.end()) {
            lowton[dfs_low[c.first]] = cnt++;
        }

        if (lowton.find(dfs_low[c.second]) == lowton.end()) {
            lowton[dfs_low[c.second]] = cnt++;
        }
        int w = mpp[ii(min(c.first, c.second), max(c.first, c.second))];
        graph2[lowton[dfs_low[c.first]]].pb(ii(lowton[dfs_low[c.second]], w));
        graph2[lowton[dfs_low[c.second]]].pb(ii(lowton[dfs_low[c.first]], w));

        // cout << lowton[dfs_low[c.first]] << " " << lowton[dfs_low[c.second]]
        // << " " << w<< "\n";
        //  cout << c.first << " " << c.second << " " << w<< "\n";
    }
    nA.assign(cnt, 0);
    nH.assign(cnt, 0);
    rep(i, 0, n) {
        if (s[i] == 'H')
            nH[lowton[dfs_low[i]]]++;
        if (s[i] == 'A')
            nA[lowton[dfs_low[i]]]++;
    }
    // rep(i,0,cnt){
    //     cout << nH[i] << " " << nA[i] << "\n";
    // }
    visited.assign(cnt, 0);
    ll ans = 0;
    rep(i, 0, cnt) {
        if (!visited[i])
            ans += dfs(i, -1);
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}