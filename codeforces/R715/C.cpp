#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
int dp[2010][2010], a[2010];
signed main() {
	cin >> n;
	memset(dp, 0x3f, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i][i] = 0;
	}
	sort(a + 1, a + 1 + n);
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			dp[l][r] = min(dp[l][r - 1], dp[l + 1][r]) + (a[r] - a[l]);
		}
	}
	cout << dp[1][n];
}