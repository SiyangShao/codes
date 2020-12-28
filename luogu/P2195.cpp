#include <bits/stdc++.h>
using namespace std;
int n, m, q, c;
vector<int> fa, d, ans;
vector<vector<int>> E;
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void merge(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}
void dfs(int u, int fa) {
	for (auto v : E[u]) {
		if (v == fa) {
			continue;
		}
		d[v] = d[u] + 1;
		if (d[v] > d[c])
			c = v;
		dfs(v, u);
	}
}
void diameter(int x) {
	x = find(x);
	c = 0;
	dfs(x, 0);
	d[c] = 0;
	dfs(c, 0);
	ans[find(x)] = d[c];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m >> q;
	fa.resize(n + 1), E.resize(n + 1), d.resize(n + 1), ans.resize(n + 1);
	iota(fa.begin(), fa.end(), 0);
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
		merge(u, v);
	}
	for (int i = 1; i <= n; ++i) {
		if (ans[find(i)] == 0) {
			diameter(i);
		}
	}
	int op, u, v;
	while (q--) {
		cin >> op;
		if (op == 1) {
			cin >> u;
			u = find(u);
			cout << ans[u] << "\n";
		} else {
			cin >> u >> v;
			u = find(u), v = find(v);
			if (u == v)
				continue;
			int tmp = (ans[u] + 1) / 2 + (ans[v] + 1) / 2 + 1;
			tmp = max(tmp, max(ans[u], ans[v]));
			fa[u] = v;
			ans[v] = tmp;
		}
	}
}