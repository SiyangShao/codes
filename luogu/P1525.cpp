#include <bits/stdc++.h>
using namespace std;
int n, m;
int fa[20001], b[20001];
void init() {
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
}
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	fa[x] = y;
}
struct Edge {
	int a, b, c;
} edge[100001];
bool cmp(Edge x, Edge y) { return x.c > y.c; }
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> edge[i].a >> edge[i].b >> edge[i].c;
	}
	sort(edge, edge + m, cmp);
	init();
	for (int i = 0; i <= m; i++) {
		if (find(edge[i].a) == find(edge[i].b)) {
			cout << edge[i].c << "\n";
			break;
		} else {
			if (!b[edge[i].a]) {
				b[edge[i].a] = edge[i].b;
			} else {
				unionSet(b[edge[i].a], edge[i].b);
			}
			if (!b[edge[i].b]) {
				b[edge[i].b] = edge[i].a;
			} else {
				unionSet(b[edge[i].b], edge[i].a);
			}
		}
	}
	return 0;
}