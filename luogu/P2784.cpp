#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 7;
int N, M, S, T;
vector<pair<int, double>> e[maxn];
double dis[maxn];
int vis[maxn];
priority_queue<pair<double, int>> q;
void dijkstra(int n, int s) {
	for (int i = 1; i <= n; ++i) {
		dis[i] = -1;
	}
	dis[s] = 1;
	q.push({1, s});
	// remember in priority queue, pair comapred first(larger begin)
	// then second (larger begin)
	while (!q.empty()) { // we want the largest begin
		auto u = q.top().second;
		q.pop();
		if (vis[u])
			continue;
		vis[u] = 1;
		for (auto ed : e[u]) {
			auto v = ed.first;
			auto w = ed.second;
			if (dis[v] < dis[u] * w) {
				dis[v] = dis[u] * w;
				q.push({dis[v],
						v}); // here to judge the maximum, so we push dis[v]
			}
		}
	}
}
int main() {
	scanf("%d%d%d%d", &N, &M, &S, &T);
	int a, b;
	double c;
	for (int i = 1; i <= M; ++i) {
		scanf("%d%d%lf", &a, &b, &c);
		e[a].push_back({b, c});
	}
	dijkstra(N, S);
	if (dis[T] == -1) {
		puts("orz");
	} else {
		printf("%.4lf", dis[T]);
	}
}