#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> q[10010];
int c[5022];
int dp[10010][2];
void dfs(int u, int fa) {
	if (u <= n)
		return;
	for (auto i : q[u]) {
		if (i == fa) {
			continue;
		}
		dfs(i, u);
		dp[u][0] += min(dp[i][0] - 1, dp[i][1]);
		dp[u][1] += min(dp[i][1] - 1, dp[i][0]);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; ++i) {
		dp[i][0] = 1;
		dp[i][1] = 1;
	}
	for (int i = 1; i <= n; ++i) {
		cin >> c[i];
		dp[i][!c[i]] = 0x3f3f3f3f;
	}
	for (int i = 1, x, y; i < m; ++i) {
		cin >> x >> y;
		q[x].push_back(y);
		q[y].push_back(x);
	}
	dfs(m, m);
	cout << min(dp[m][0], dp[m][1]);
}