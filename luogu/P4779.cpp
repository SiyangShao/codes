#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
int dis[maxn], vis[maxn];
vector<pair<int, int>> e[maxn];
priority_queue<pair<int, int>> q;
void dijkstra(int n, int s) {
	memset(dis, 63, sizeof(dis));
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		// want the smallest begin
		int u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto ed : e[u]) {
			int v = ed.first, w = ed.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({-dis[v], v});
				// cause in priority queue, first larger one begin
				// we push - dis[v] to ensure
				// it's the nearst begin point
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, m, s;
	cin >> n >> m >> s;
	for (int i = 1, u, v, w; i <= m; ++i) {
		cin >> u >> v >> w;
		e[u].push_back({v, w});
	}
	dijkstra(n, s);
	for (int i = 1; i <= n; ++i) {
		cout << dis[i] << " ";
	}
}