#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int N = 2e5 + 7;
ll n, sum;
vector<ll> E[N];
ll siz[N], dp[N];
ll dfs(int u, int fa) {
	siz[u] = 1;
	for (auto v : E[u]) {
		if (v == fa)
			continue;
		siz[u] += dfs(v, u);
	}
	sum += siz[u];
	return siz[u];
}
void dfs2(int u, int fa) {
	for (auto v : E[u]) {
		if (v == fa)
			continue;
		dp[v] = dp[u] + n - siz[v] * 2;
		sum = max(sum, dp[v]);
		dfs2(v, u);
	}
}
void solve() {
	cin >> n;
	for (ll i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	dfs(1, 0);
	dp[1] = sum;
	dfs2(1, 0);
	cout << sum;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}