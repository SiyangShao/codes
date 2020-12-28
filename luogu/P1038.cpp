#include <bits/stdc++.h>
using namespace std;
int n, p;
int c[110], U[110], dep[110], deep = 1, vis[110];
vector<pair<int, int>> E[110];
queue<int> Q;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> n >> p;
	for (int i = 1; i <= n; ++i) {
		cin >> c[i] >> U[i];
		if (c[i] != 0) {
			Q.push(i);
			dep[i] = 1;
		} else
			c[i] -= U[i];
	}
	for (int i = 1, u, v, w; i <= p; ++i) {
		cin >> u >> v >> w;
		E[u].push_back({v, w});
	}
	while (!Q.empty()) {
		auto u = Q.front();
		Q.pop();
		if (c[u] > 0)
			for (auto v : E[u]) {
				if (!dep[v.first])
					Q.push(v.first);
				dep[v.first] = max(dep[v.first], dep[u] + 1);
				deep = max(deep, dep[v.first]);
				c[v.first] += c[u] * v.second;
				// cout << v.first << " " << c[v.first] << "\n";
			}
	}
	int num = 0;
	for (int i = 1; i <= n; ++i) {
		if (dep[i] == deep) {
			if (c[i] > 0) {
				cout << i << " " << c[i] << "\n";
				num++;
			}
		}
	}
	if (num == 0) {
		cout << "NULL";
	}
}