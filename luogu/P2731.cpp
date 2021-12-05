#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int n, rd;
int mp[N][N];
int degree[N];
int road[N * N];
void dfs(int u) {
	for (int v = 1; v <= n; ++v) {
		if (mp[u][v]) {
			mp[u][v]--;
			mp[v][u]--;
			dfs(v);
		}
	}
	road[++rd] = u;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int m;
	cin >> m;
	for (int i = 1, u, v; i <= m; ++i) {
		cin >> u >> v;
		mp[u][v]++;
		mp[v][u]++;
		degree[u]++, degree[v]++;
		n = n > u && n > v ? n : (u > v ? u : v);
	}
	int start = 1;
	for (int i = 1; i <= n; ++i) {
		if (degree[i] % 2) {
			start = i;
			break;
		}
	}
	dfs(start);
	for (int i = rd; i >= 1; --i) {
		cout << road[i] << "\n";
	}
}