#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// Case1: everyone dead in the first round
// dp[n][x] = min(n-1,x)^n
// Case 2: x>=n, then chose the number dead each round to k
// 0<=k <n-1
// dp[n][x] += \sum_{k=0}^{n-2} (n-1)^k * dp[n-k][x-n+1]* C_n^i
const ll mod = 998244353;
const ll N = 510;
ll dp[N][N], c[N][N];
ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) {
			res = res * a % mod;
		}
		b >>= 1ll;
		a = a * a % mod;
	}
	return res;
}
ll dfs(int n, int x) {
	if (dp[n][x]) {
		return dp[n][x];
	}
	dp[n][x] = qpow(min(x, n - 1), n);
	if (x < n) {
		return dp[n][x];
	}
	for (int i = 0; i < n - 1; ++i) {
		dp[n][x] +=
			qpow(n - 1, i) * dfs(n - i, x - n + 1) % mod * c[n][i] % mod;
		dp[n][x] %= mod;
	}
	return dp[n][x];
}
int main() {
#ifdef DEBUG
	auto now = clock();
#endif
	ll n, x;
	scanf("%lld%lld", &n, &x);
	for (int i = 0; i <= 500; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 || j == 0) {
				c[i][j] = 1;
			} else {
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			}
		}
	}
	printf("%lld\n", dfs(n, x));
#ifdef DEBUG
	printf("=====================");
	printf("Program run for %gms.\n",
		   (clock() - now) / (double)CLOCKS_PER_SEC * 1000);
#endif
}