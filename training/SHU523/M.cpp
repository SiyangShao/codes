#include <bits/stdc++.h>
using namespace std;
const int maxn = 210;
vector<int> p[maxn];
int dp[maxn][maxn], val[maxn], n, m;
void dfs(int x, int w) {
	dp[x][1] = val[x];
	for (auto to : p[x]) {
		dfs(to, w - 1);
		for (int v = w; v > 1; v--) {
			for (int k = 0; k < v; k++) {
				dp[x][v] = max(dp[x][v], dp[x][v - k] + dp[to][k]);
			}
		}
	}
}
int main() {
	while (~scanf("%d%d",&n,&m)) {
		if (n == 0 || m == 0) {
			break;
		}
		memset(dp, 0, sizeof(dp));
		memset(p,0,sizeof(p));
		for (int i = 1,a,b; i <= n; i++) {
			scanf("%d%d", &a, &b);
			p[a].push_back(i);
			val[i] = b;
		}
		m++;
		dfs(0, m);
		printf("%d\n", dp[0][m]);
	}
	return 0;
}