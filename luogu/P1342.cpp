#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6 + 7;
int n, m;
vector<pair<int, int>> e[maxn], re[maxn];
priority_queue<pair<int, int>> q;
int dis[maxn], vis[maxn];
void dijkstra(int s, vector<pair<int, int>> vec[]) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	dis[s] = 0;
	q.push({dis[s], s});
	while (!q.empty()) {
		auto u = q.top().second;
		q.pop();
		if (vis[u]) {
			continue;
		}
		vis[u] = 1;
		for (auto nxt : vec[u]) {
			auto v = nxt.second, w = nxt.first;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({-dis[v], v});
			}
		}
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[u].push_back({w, v});
		re[v].push_back({w, u});
	}
	dijkstra(1, e);
	int ans = 0;
	for (int i = 2; i <= n; ++i) {
		ans += dis[i];
	}
	dijkstra(1, re);
	for (int i = 2; i <= n; ++i) {
		ans += dis[i];
	}
	cout << ans;
}