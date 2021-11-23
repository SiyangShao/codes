#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int c, u, v, w;
int dis[110][110];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	memset(dis, 0x3f, sizeof(dis));
	for (int i = 1; i <= n; ++i) {
		dis[i][i] = 0;
	}
	while (m--) {
		cin >> c;
		if (c == 0) {
			cin >> u >> v;
			if (dis[u][v] >= dis[0][0]) {
				cout << "-1\n";
			} else {
				cout << dis[u][v] << "\n";
			}
		} else {
			cin >> u >> v >> w;
			if (w < dis[u][v]) {
				dis[u][v] = w;
				dis[v][u] = w;
				for (int i = 1; i <= n; ++i) {
					for (int j = 1; j <= n; ++j) {
						dis[i][j] =
							min(dis[i][j], dis[i][u] + dis[u][v] + dis[v][j]);
						dis[j][i] = dis[i][j];
					}
				}
			}
		}
	}
}