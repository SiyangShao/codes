#include <bits/stdc++.h>
using namespace std;
const int maxn = 2010;
int n, m;
vector<pair<double, int>> e[maxn];
priority_queue<pair<double, int>> q;
double dis[maxn];
int vis[maxn];
void dijkstra(int s) {
	dis[s] = 1;
	q.push({dis[s], s});
	while (!q.empty()) {
		auto point = q.top().second;
		q.pop();
		if (vis[point])
			continue;
		for (auto nxt : e[point]) {
			auto v = nxt.second;
			auto w = nxt.first;
			if (dis[v] < dis[point] * w) {
				dis[v] = dis[point] * w;
				q.push({dis[v], v});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1, x, y, z; i <= m; ++i) {
		cin >> x >> y >> z;
		e[x].push_back({1.0 - z / 100.0, y});
		e[y].push_back({1.0 - z / 100.0, x});
	}
	int a, b;
	cin >> a >> b;
	dijkstra(a);
	printf("%.8lf", 100.0 / dis[b]);
}