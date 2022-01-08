#include <cstring>
#include <vector>
#include <map>
#include <stdio.h>
#include <algorithm>
using namespace std;
const int N = 2e5 + 10;
int n, c, d[N], d2[N], d1[N];
vector<int> E[N];
map<pair<int, int>, int> mp;
void dfs(int u, int fa) {
	for (int v : E[u]) {
		if (v == fa)
			continue;
		d[v] = d[u] + mp[make_pair(u, v)];
		if (d[v] > d[c])
			c = v;
		dfs(v, u);
	}
}
void dfss(int u, int fa) {
	for (int v : E[u]) {
		if (v == fa)
			continue;
		d2[v] = d2[u] + mp[make_pair(u, v)];
		if (d2[v] > d2[c])
			c = v;
		dfss(v, u);
	}
}
void dfsss(int u, int fa) {
	for (int v : E[u]) {
		if (v == fa)
			continue;
		d1[v] = d1[u] + mp[make_pair(u, v)];
		if (d1[v] > d1[c])
			c = v;
		dfsss(v, u);
	}
}
int main() {
	while (~scanf("%d", &n)) {
		memset(E, 0, sizeof(E));
		memset(d, 0, sizeof(d));
		mp.clear();
		for (int i = 2; i <= n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			mp[make_pair(i, u)] = v;
			mp[make_pair(u, i)] = v;
			E[i].push_back(u), E[u].push_back(i);
		}
		dfs(1, 0);
		dfss(c, 0);
		dfsss(c, 0);
		for (int i = 1; i <= n; i++) {
			printf("%d\n", max(d1[i], d2[i]));
			d1[i] = 0;
			d2[i] = 0;
		}
	}
	return 0;
}