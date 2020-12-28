#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 7;
int n, m, fa[maxn], k, sum;
vector<int> line[maxn];
int vis[maxn], q[maxn], ans[maxn];
inline void init() {
	for (int i = 0; i <= n; i++) {
		fa[i] = i;
	}
}
int find(int x) {
	if (x != fa[x]) {
		fa[x] = find(fa[x]);
	}
	return fa[x];
}
inline void unionSet(int x, int y) {
	x = find(x);
	y = find(y);
	if (x != y) {
		fa[x] = y;
		sum--;
	}
}
int main() {
	cin >> n >> m;
	sum = n;
	init();
	for (int i = 1, j, k; i <= m; i++) {
		cin >> j >> k;
		line[j].push_back(k);
		line[k].push_back(j);
	}
	cin >> k;
	for (int i = 1; i <= k; i++) {
		cin >> q[i];
		vis[q[i]] = 1;
	}
	for (int i = 0; i < n; i++) {
		if (vis[i] == 0) {
			for (auto j : line[i]) {
				if (vis[j] == 0)
					unionSet(j, i);
			}
		}
	}
	for (int i = k; i >= 1; i--) {
		vis[q[i]] = 0;
		ans[i] = sum;
		for (auto j : line[q[i]]) {
			if (vis[j] == 0) {
				unionSet(j, q[i]);
			}
		}
	}
	cout << sum << "\n";
	for (int i = 1; i <= k; i++) {
		cout << ans[i]-i << "\n";
	}
}