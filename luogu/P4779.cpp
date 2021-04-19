// Dijkstra 模板 堆优化 复杂度为O((n+m)logn)
#include <bits/stdc++.h>
const int maxn = 1e5 + 10, maxm = 2e5 + 10;
int head[maxn], dis[maxn], cnt;
bool vis[maxn];
int n, m, s;
struct edge {
	int to, nxt, dis;
} e[maxm];
struct node {
	int dis;
	int pos;
	bool operator<(const node &x) const { return x.dis < dis; }
};
std::priority_queue<node> q;
inline void add_edge(int u, int v, int w) {
	cnt++;
	e[cnt].dis = w;
	e[cnt].to = v;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
inline void dijkstra() {
	dis[s] = 0;
	q.push(node{0, s});
	while (!q.empty()) {
		node tmp = q.top();
		q.pop();
		int x = tmp.pos, d = tmp.dis;
		if (vis[x])
			continue;
		vis[x] = 1;
		for (int i = head[x]; i; i = e[i].nxt) {
			int y = e[i].to;
			if (dis[y] > dis[x] + e[i].dis) {
				dis[y] = dis[x] + e[i].dis;
				if (!vis[y]) {
					q.push((node){dis[y], y});
				}
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &s);
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 0, u, v, w; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &w);
		add_edge(u, v, w);
	}
	dijkstra();
	printf("0");
	for (int i = 2; i <= n; i++) {
		printf(" %d", dis[i]);
	}
	printf("\n");
}