#include <bits/stdc++.h>
using namespace std;
int q[101][101];
int sum = 0;
int i, j, n, m, t, sx, sy, x, y, ex, ey;
void dfs(int a, int b) {
	if (a == ex && b == ey)	 //终止条件
	{
		sum++;
		return;
	} else {
		q[a][b] = 0;  //保存结果
		if (q[a - 1][b] != 0) {
			dfs(a - 1, b);
			q[a - 1][b] = 1;
		}
		if (q[a][b - 1] != 0) {
			dfs(a, b - 1);
			q[a][b - 1] = 1;
		}
		if (q[a][b + 1] != 0) {
			dfs(a, b + 1);
			q[a][b + 1] = 1;
		}
		if (q[a + 1][b] != 0) {
			dfs(a + 1, b);
			q[a + 1][b] = 1;
		}  //这四部是穷举所有可行的搜索，并且回溯
	}
}
int main() {
	memset(q, 0, sizeof(q));  //边界当作障碍。
	cin >> n >> m >> t;
	cin >> sx >> sy >> ex >> ey;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++) q[i][j] = 1;  //可以走
	for (i = 1; i <= t; i++) {
		cin >> x >> y;
		q[x][y] = 0;  //障碍物初始化
	}
	dfs(sx, sy);
	cout << sum << endl;
	return 0;
}