#include <bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][101][5051];
int T, n, tmp, ans;
int a[101], b[101], c[101];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i] >> c[i];
		}
		dp[n%2][1][n] = a[n];
		tmp = (n + 1) * n / 2;
		for (int i = n - 1; i >= 1; --i) {
			for (int j = n - i + 1; j >= 1; --j) {
				for (int k = tmp; k >= n; --k) {
					if (dp[(i + 1)%2][j][k] != -1) {
						dp[i%2][j][k] =
							dp[(i + 1)%2][j][k] + max(c[i] * j, b[i] * (k - i * j));
					}
					if (k >= i + n && j >= 2 && dp[(i + 1)%2][j - 1][k - i] != -1) {
						dp[i%2][j][k] =
							max(dp[i%2][j][k], dp[(i + 1)%2][j - 1][k - i] + a[i]);
					}
				}
			}
		}
		ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= tmp; ++j) {
				ans = max(ans, dp[1][i][j]);
			}
		}
		cout << ans << "\n";
	}
}