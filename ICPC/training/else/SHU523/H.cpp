#include <algorithm>
#include <cstdio>
#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <string.h>
using namespace std;
int dp[100005], sum[100005], v[105], c[105];
int main() {
	int i, j, n, m;
	while (cin >> n >> m) {
		if (n == 0 || m == 0)
			break;
		for (i = 1; i <= n; i++) {
			cin >> v[i];
		}
		for (i = 1; i <= n; i++) {
			cin >> c[i];
		}
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		int ans = 0;
		for (i = 1; i <= n; i++) {
			memset(sum, 0, sizeof(sum));
			for (j = v[i]; j <= m; j++) {
				if (!dp[j] && dp[j - v[i]] && sum[j - v[i]] < c[i]) {
					dp[j] = 1;
					sum[j] = sum[j - v[i]] + 1;
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}