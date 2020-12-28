#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int _, n;
vector<int> mp[20];
vector<int> E[N];
vector<int> color[2];
int ans[N], vis[N];
void init() {
	for (int i = 1; i <= N; ++i) {
		mp[int(log(i) / log(2))].push_back(i);
	}
}
void dfs(int u, int fa, int depth) {
	for (auto i : E[u]) {
		if (i == fa)
			continue;
		if (depth % 2 == 1) {
			color[1].push_back(i);
		} else {
			color[0].push_back(i);
		}
		dfs(i, u, depth + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	cin >> _;
	while (_--) {
		memset(E, 0, sizeof(E));
		memset(color, 0, sizeof(color));
		memset(ans, 0, sizeof(ans));
		memset(vis, 0, sizeof(vis));
		cin >> n;
		for (int i = 1, u, v; i < n; ++i) {
			cin >> u >> v;
			E[u].push_back(v);
			E[v].push_back(u);
		}
		color[0].push_back(1);
		dfs(1, 0, 1);
		int tmp = color[1].size();
		auto top1 = color[1].begin();
		auto top2 = color[0].begin();
		int begin = 0;
		cout << tmp << "\n";
		if (tmp != 0) {
			cout << color[1][0] << ":";
		}
		while (tmp) {
			if (tmp & 1) {
				for (auto i : mp[begin]) {
					if (i <= n) {
						ans[*top1] = i;
						vis[i] = 1;
						top1++;
					}
				}
			}
			tmp /= 2;
			begin++;
		}
		for (int i = 1; i <= n; ++i) {
			if (!vis[i]) {
				ans[i] = *top2;
				top2++;
			}
		}
		for (int i = 1; i <= n; ++i) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
}