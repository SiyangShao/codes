#include <cstring>
#include <iomanip>
#include <iostream>
#include <vector>
const int maxn = 2e5 + 10;
using namespace std;
struct node {
	int v, w;
	node(int x, int y) : v(x), w(y) {}
};
int n;
vector<node> e[maxn];
bool visit[maxn];
int ans, p;
void dfs(int u, int dis) {
	if (dis > ans)
		ans = dis, p = u;
	visit[u] = 1;
	for (int i = 0; i < e[u].size(); i++) {
		int v = e[u][i].v;
		if (!visit[v])
			dfs(v, dis + e[u][i].w);
	}
}
int main() {
	int m, a, b, c;
	char tmp;
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d %d %d %c", &a, &b, &c, &tmp);
		e[a].push_back(node(b, c));
		e[b].push_back(node(a, c));
	}
	ans = 0, p = 0;
	memset(visit, 0, sizeof(visit));
	dfs(1, 0);
	ans = 0;
	memset(visit, 0, sizeof(visit));
	dfs(p, 0);
	printf("%d\n", ans);
}