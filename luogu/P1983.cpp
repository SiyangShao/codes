#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int n, m, ans;
vector<int> E[1010];
int c[1010], dep[1010];
int si[1010], in[1010], mp[1010][1010];
bool dfs(int u) {
	c[u] = -1;
	for (auto v : E[u]) {
		if (c[v] < 0)
			return false;
		else if (!c[v])
			if (!dfs(v))
				return false;
		dep[u] = max(dep[u], dep[v] + 1);
	}
	c[u] = 1;
	return true;
}
bool toposort() {
	for (int u = 1; u <= n; u++)
		if (!c[u])
			if (!dfs(u))
				return false;
	return true;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m;
	for (int k = 1; k <= m; ++k) {
		int s;
		memset(in, 0, sizeof(in));
		cin >> s;
		for (int i = 1; i <= s; ++i) {
			cin >> si[i];
			in[si[i]] = 1;
		}
		for (int i = si[1]; i <= si[s]; ++i) {
			if (in[i] == 0) {
				for (int j = 1; j <= s; ++j) {
					if (mp[si[j]][i] == 0) {
						E[si[j]].emplace_back(i);
						mp[si[j]][i] = 1;
					}
				}
			}
		}
	}
	toposort();
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, dep[i]);
	}
	cout << ans + 1;
}