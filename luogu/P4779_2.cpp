#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7;
struct edge {
	int v, w;
};
struct node {
	int dis, u;
	bool operator>(const node &a) const { return dis > a.dis; }
};
vector<edge> e[maxn];
int dis[maxn], vis[maxn];
priority_queue<node, vector<node>, greater<node>> q;
void dijkstra(int n, int s) {
	memset(dis, 63, sizeof(dis));
	dis[s] = 0;
	q.push({0, s});
	while (!q.empty()) {
		int u = q.top().u;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto ed : e[u]) {
			int v = ed.v, w = ed.w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push({dis[v], v});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, s, m;
	cin >> n >> m >> s;
	for (int i = 0, u, v, w; i < m; ++i) {
		cin >> u >> v >> w;
		edge tmp;
		tmp.v = v, tmp.w = w;
		e[u].push_back(tmp);
	}
	dijkstra(n, s);
	for (int i = 1; i <= n; ++i) {
		cout << dis[i] << " ";
	}
}