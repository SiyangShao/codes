#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> e[10010];
int s, t, n, m;
int dis[10010], vis[10010];
priority_queue<pair<int, int>> q;
void dijkstra(int s) {
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		auto edge = q.top();
		auto u = edge.second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto nxt : e[u]) {
			auto v = nxt.second, w = nxt.first;
			if (dis[v] > max(dis[u], w)) {
				dis[v] = max(dis[u], w);
				q.push({-dis[v], v});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> s >> t;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[v].push_back({w, u});
		e[u].push_back({w, v});
	}
	dijkstra(s);
	cout << dis[t];
}