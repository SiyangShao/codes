#include <bits/stdc++.h>
using namespace std;
// Hungarian algorithm for maximum matching
constexpr int N = 510;
int V; // number of vertices
// Bipartite
vector<int> E[N];
vector<int> color(N);
bool dfs(int v, int c) {
	color[v] = c;
	for (auto u : E[v]) {
		if (color[u] == c)
			continue;
		if (color[u] == 0 && !dfs(u, -c))
			return false;
	}
	return true;
}
bool solve() {
	// Check whether the graph is bipartite
	for (int i = 0; i < V; ++i) {
		if (color[i] == 0) {
			if (!dfs(i, 1))
				return false;
		}
	}
	return true;
}
// Here is Hungarian algorithm for maximum matching
int match[N], ask[N];
int vis[N][N];
int n, m, e;
bool found(int x) {
	// Find extention rouad
	for (int i = 1; i <= m; ++i) {
		if (vis[x][i]) {
			if (ask[i])
				continue;
			ask[i] = 1;
			if (!match[i] || found(match[i])) {
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}
inline int MATCH() {
	int cnt = 0;
	memset(match, 0, sizeof(match));
	for (int i = 1; i <= n; ++i) {
		memset(ask, 0, sizeof(ask));
		if (found(i))
			cnt++;
	}
	return cnt;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> m >> e;
	for (int i = 0, u, v; i < e; ++i) {
		cin >> u >> v;
		vis[u][v] = 1;
	}
	cout << MATCH() << "\n";
}