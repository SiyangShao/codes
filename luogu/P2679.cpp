#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;
int dp[2][210][210][3]; //表示A的前i个选k个与B的前j配对
int n, m, k;
string a, b;
signed main() {
	cin >> n >> m >> k >> a >> b;
	memset(dp, 0, sizeof(dp));
	dp[0][0][0][0] = 1;
	dp[1][0][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int p = 1; p <= k; p++) {
				if (a[i - 1] == b[j - 1]) { //匹配上了
					dp[i % 2][j][p][1] =
						dp[(i - 1) % 2][j - 1][p][1] + // 上一位匹配同种
						dp[(i - 1) % 2][j - 1][p - 1][0] + // 上一位不匹配
						dp[(i - 1) % 2][j - 1][p - 1][1]; // 上一位匹配，不同种
					dp[i % 2][j][p][1] %= mod;
					dp[i % 2][j][p][0] =
						dp[(i - 1) % 2][j][p][0] + dp[(i - 1) % 2][j][p][1]; // 不纳入匹配
					dp[i % 2][j][p][0] %= mod;
				} else {
					dp[i % 2][j][p][0] =
						dp[(i - 1) % 2][j][p][0] + dp[(i - 1) % 2][j][p][1]; // 不纳入匹配
					dp[i % 2][j][p][0] %= mod;
					dp[i % 2][j][p][1] = 0; // 无法纳入匹配
				}
			}
		}
	}
	cout << (dp[n % 2][m][k][0] + dp[n % 2][m][k][1]) % mod;
}