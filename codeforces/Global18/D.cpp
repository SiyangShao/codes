#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> E;
vector<int> fa, dis;
unordered_map<int, int> mp;
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
inline void merge(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}
void dfs(int u, int fa) {
	for (auto i : E[u]) {
		auto v = i.first, w = i.second;
		if (v == fa)
			continue;
		if (w != -1) {
			cout << u << " " << v << " " << w << "\n";
		} else {
			cout << u << " " << v << " " << int(dis[u] ^ dis[v]) << "\n";
		}
		dfs(v, u);
	}
}
void solve() {
	int n, q;
	cin >> n >> q;
	E.clear(), fa.clear(), dis.clear(), mp.clear();
	E.resize(n + 1), fa.resize(2 * n + 1), dis.resize(n + 1);
	iota(fa.begin(), fa.end(), 0);
	for (int i = 1, u, v, w; i < n; ++i) {
		cin >> u >> v >> w;
		E[u].push_back({v, w});
		E[v].push_back({u, w});
		if (w != -1) {
			w = __builtin_popcount(w) % 2;
			if (w % 2) {
				merge(u, v + n), merge(v, u + n);
			} else {
				merge(u, v), merge(u + n, v + n);
			}
		}
	}
	for (int i = 1, u, v, w; i <= q; ++i) {
		cin >> u >> v >> w;
		if (w % 2) {
			merge(u, v + n), merge(v, u + n);
		} else {
			merge(u, v), merge(u + n, v + n);
		}
	}
	// for (int i = 1; i <= n + n; ++i) {
	// 	cout << find(i) << " ";
	// }
	// cout << "\n";
	for (int i = 1; i <= n; ++i) {
		// cout << find(i) << "\n";
		if (find(i) == find(i + n)) {
			cout << "NO\n";
			return;
		}
		// if (find(i) == find(1)) {
		// 	dis[i] = 0;
		// } else if (find(i + n) == find(1)) {
		// 	dis[i] = 1;
		// } else {
		// 	dis[i] = 0;
		// 	// cout << "NO\n";
		// 	// return;
		// }
		if (mp[find(i)] == 0 && mp[find(i + n)] == 0) {
			mp[find(i)] = 2;
			mp[find(i + n)] = 1;
		}
		dis[i] = mp[find(i)] % 2;
	}
	cout << "YES\n";
	dfs(1, 0);
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