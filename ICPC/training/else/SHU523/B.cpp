#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<long long, long long>
const int maxn = 2010;
int mp[maxn][maxn], d1[maxn][maxn], d2[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m, w;
queue<pii> q;
void bfs1(pii x) {
	q.push(x);
	while (q.size()) {
		pii t = q.front();
		q.pop();
		vis[t.first][t.second] = false;
		for (int i = 0; i < 4; i++) {
			int a = dx[i] + t.first, b = dy[i] + t.second;
			if (a < 1 || a > n || b < 1 || b > m) {
				continue;
			}
			if (mp[a][b] == -1) {
				continue;
			}
			if (d1[a][b] > d1[t.first][t.second] + w) {
				d1[a][b] = d1[t.first][t.second] + w;
				if (!vis[a][b]) {
					q.push({a, b});
					vis[a][b] = true;
				}
			}
		}
	}
}
void bfs2(pii x) {
	q.push(x);
	while (q.size()) {
		pii t = q.front();
		q.pop();
		vis[t.first][t.second] = false;
		for (int i = 0; i < 4; i++) {
			int a = dx[i] + t.first, b = dy[i] + t.second;
			if (a < 1 || a > n || b < 1 || b > m) {
				continue;
			}
			if (mp[a][b] == -1) {
				continue;
			}
			if (d2[a][b] > d2[t.first][t.second] + w) {
				d2[a][b] = d2[t.first][t.second] + w;
				if (!vis[a][b]) {
					q.push({a, b});
					vis[a][b] = true;
				}
			}
		}
	}
}
signed main() {
	cin >> n >> m >> w;
	memset(d1, 0x3f, sizeof(d1));
	memset(d2, 0x3f, sizeof(d2));
	d1[1][1] = 0;
	d2[n][m] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%lld", &mp[i][j]);
		}
	}
	if (mp[n][m] == -1 || mp[1][1] == -1) {
		printf("-1\n");
		return 0;
	}
	bfs1({1, 1});
	bfs2({n, m});
	int ans = 0x3f3f3f3f3f3f3f3f, res1 = 0x3f3f3f3f3f3f3f3f, res2 = 0x3f3f3f3f3f3f3f3f;
	vector<pii> x1, x2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// cout << d1[i][j] << " " << d2[i][j] << "\n";
			ans = min(ans, d1[i][j] + d2[i][j]);
			if (mp[i][j] > 0) {
				d1[i][j] += mp[i][j];
				d2[i][j] += mp[i][j];
				res1 = min(res1, d1[i][j]);
				res2 = min(res2, d2[i][j]);
			}
		}
	}
	ans = min(ans, res1 + res2);
	if (ans >= 0x3f3f3f3f3f3f3f3f/2 ) {
		printf("-1\n");
	} else {
		printf("%lld\n", ans);
	}
}