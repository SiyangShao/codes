#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 7;
int n, k;
int d[N], f[N], c;
vector<int> E[N];
int deep[N], len[N], a[N], vis[N];
void dfs(int u, int fa) {
	for (auto v : E[u]) {
		if (v == fa)
			continue;
		d[v] = d[u] + 1;
		if (d[v] > d[c])
			c = v;
		dfs(v, u);
	}
}
void dfs2(int u, int fa) {
	for (auto v : E[u]) {
		if (v == fa)
			continue;
		d[v] = d[u] + 1;
		f[v] = u;
		if (d[v] > d[c])
			c = v;
		dfs2(v, u);
	}
}
void dp(int u, int fa) {
	len[u] = deep[u];
	for (auto v : E[u]) {
		if (v == fa)
			continue;
		deep[v] = deep[u] + 1;
		dp(v, u);
		len[u] = max(len[u], len[v]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> k;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	dfs(1, 0);
	memset(d, 0, sizeof(d));
	dfs2(c, 0);
	int kkk = c;
	for (int i = 1; i <= (d[c] + 1) / 2; ++i)
		kkk = f[kkk];
	// cout << kkk << "\n";
	dp(kkk, 0);
	iota(a + 1, a + 1 + n, 1);
	sort(a + 1, a + 1 + n,
		 [&](int x, int y) { return len[x] - deep[x] > len[y] - deep[y]; });
	int ans = 0;
	for (int i = k + 1; i <= n; ++i) {
		// cout << a[i] << " " << len[a[i]] << " " << deep[a[i]] << "\n";
		ans = max(ans, len[a[i]] - deep[a[i]] + 1);
	}
	cout << ans;
}