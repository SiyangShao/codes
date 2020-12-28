#include <bits/stdc++.h>
using namespace std;
int n, m, t;
struct node1 {
	int i, j;
	int l;
} a[10010];
bool cmp(node1 x, node1 y) { return x.l < y.l; }
int vis[101][101];
int run[101][101];
int tmp[101][101];
int vi[101][101];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(vis, 0, sizeof(vis));
		memset(vi, 0, sizeof(vi));
		int q = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[++q].l;
				a[q].i = i;
				a[q].j = j;
				tmp[i][j] = a[q].l;
			}
		}
		sort(a + 1, a + 1 + q, cmp);
		int s = 1;
		for (int i = 1; i <= q; i++) {
			int p = a[i].i, l = a[i].l;
			if (vis[s][p] == 0) {
				vis[s][p] = 1;
				run[s][p] = l;
				vi[a[i].i][a[i].j] = 1;
				s++;
			}
			if (s > m) {
				break;
			}
		}
		for (int i = 1; i <= n; i++) {
			int q = 1;
			for (int j = 1; j <= m; j++) {
				if (!vis[j][i]) {
					while (vi[i][q] == 1) {
						q++;
					}
					run[j][i] = tmp[i][q];
                    q++;
				}
				cout << run[j][i] << " ";
			}
			cout << "\n";
		}
	}
}