#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)
#define int ll
using namespace std;
typedef long long ll;
constexpr int N = 1e6 + 7;
int n;
vector<int> E[N];
int dep[N], siz[N], dp[N];
void dfs(int x, int fa) {
	siz[x] = 1;
	for (auto i : E[x]) {
		if (i == fa) {
			continue;
		}
		dep[i] = dep[x] + 1;
		dfs(i, x);
		siz[x] += siz[i];
	}
}
void _dp(int x, int fa) {
	for (auto i : E[x]) {
		if (i == fa)
			continue;
		dp[i] = dp[x] + n - 2 * siz[i];
		_dp(i, x);
	}
}
signed main() {
	IO;
	cin >> n;
	for (int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; ++i) {
		dp[i] += dep[i];
	}
	_dp(1, 0);
	int ans = 0, num = 1;
	for (int i = 1; i <= n; ++i) {
		if (ans < dp[i]) {
			ans = dp[i];
			num = i;
		}
	}
	cout << num;
}