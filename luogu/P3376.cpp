#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Network flow
constexpr int N = 10010;
ll n, m, s, t;
// n: number of points, m: number of edges, s: source, t: sink
ll cnt = 1;
ll pre[N], to[N], nxt[N], val[N];
inline void addE(ll u, ll v, ll w) {
	cnt++;
	to[cnt] = v;
	val[cnt] = w;
	nxt[cnt] = pre[u];
	pre[u] = cnt;
}
ll dep[N], q[N], l, r;
bool bfs() {
	memset(dep, 0, sizeof(dep));
	q[l = r = 1] = s;
	dep[s] = 1;
	while (l <= r) {
		int u = q[l++];
		for (int p = pre[u]; p; p = nxt[p]) {
			int v = to[p];
			if (val[p] && !dep[v]) {
				dep[v] = dep[u] + 1;
				q[++r] = v;
			}
		}
	}
	return dep[t];
}
ll dfs(int u, ll in) {
	if (u == t)
		return in;
	ll out = 0;
	for (int p = pre[u]; p and in; p = nxt[p]) {
		int v = to[p];
		if (val[p] and dep[v] == dep[u] + 1) {
			auto res = dfs(v, min(val[p], in) );
			val[p] -= res;
			val[p ^ 1] += res;
			in -= res;
			out += res;
		}
	}
	if (out == 0)	
		dep[u] = 0;
	return out;
}
int main() {
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m >> s >> t;
	for (ll i = 1; i <= m; ++i) {
		ll u, v, w;
		cin >> u >> v >> w;
		addE(u, v, w);
		addE(v, u, 0);
	}
	ll ans = 0;
	while (bfs()) {
		ans += dfs(s, 1e18);
	}
	cout << ans << "\n";
	return 0;
}