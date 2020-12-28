#include <bits/stdc++.h>
using namespace std;
const int N = 201;
int dis[N][N], a[N];
int n, m, q;
inline void update(int k) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = i == j ? 0 : 0x3f3f3f3f;
		}
	}
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1, u, v, w; i <= m; i++) {
		cin >> u >> v >> w;
		u++;
		v++;
		dis[u][v] = dis[v][u] = min(w, dis[u][v]);
	}
	cin >> q;
	int i = 1;
	while (q--) {
		int x, y, r;
		cin >> x >> y >> r;
		x++;
		y++;
		while (a[i] <= r && i <= n) {
			update(i);
			i++;
		}
		if (a[x] > r || a[y] > r) {
			cout << "-1\n";
		} else {
			if (dis[x][y] == 0x3f3f3f3f) {
				cout << "-1\n";
			} else {
				cout << dis[x][y] << "\n";
			}
		}
	}
}