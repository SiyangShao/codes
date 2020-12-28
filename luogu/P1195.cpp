#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
int n, m, k, x, y, l, sum, ans;
int fa[N];
struct Edge {
	int u, v, w;
	bool operator<(Edge a) const { return w < a.w; }
} edge[N * 10];
int find(int x) { return fa[x] == x ? fa[x] : fa[x] = find(fa[x]); }
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	}
	sort(edge + 1, edge + m + 1);
	for (int i = 1; i <= m; i++) {
		int fx = find(edge[i].u), fy = find(edge[i].v);
		if (fx != fy) {
			fa[fx] = fy;
			sum++;
			ans += edge[i].w;
		}
		if (sum == n - k) {
			printf("%d", ans);
			return 0;
		}
	}
	puts("No Answer");
	return 0;
}