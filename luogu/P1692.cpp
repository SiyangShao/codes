#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> e[10010];
vector<pair<int, int>> re[10010];
int sum = 0, n, m;
int dis[10010], vis[10010];
priority_queue<pair<int, int>> q;
void dijkstra(int s, vector<pair<int, int>> vec[]) {
	memset(dis, 0x3f, sizeof(dis));
	memset(vis, 0, sizeof(vis));
	while (!q.empty()) {
		q.pop();
	}
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		auto edge = q.top();
		auto u = edge.second;
		q.pop();
		if (vis[u])
			continue;
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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[u].push_back({w, v});
		re[v].push_back({w, u});
	}
	dijkstra(1, e);
	for (int i = 2; i <= n; ++i) {
		sum += dis[i];
	}
	dijkstra(1, re);
	for (int i = 2; i <= n; ++i) {
		sum += dis[i];
	}
	cout << sum << "\n";
}