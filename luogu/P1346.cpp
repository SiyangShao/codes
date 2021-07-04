#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 110;
int d[MAXN][MAXN];
int main() {
	memset(d, 0x3f, sizeof(d));
	int n, m, s, t, v;
	scanf("%d%d%d", &n, &s, &t);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &m);
		for (int j = 1; j <= m; j++) {
			scanf("%d", &v);
			d[i][v] = (j == 1) ? 0 : 1;
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				if (i == j || i == k || j == k) continue;
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
	printf("%d", (d[s][t] == 0x3f3f3f3f) ? -1 : d[s][t]);
	return 0;
}