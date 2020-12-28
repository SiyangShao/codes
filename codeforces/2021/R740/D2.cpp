#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 4e6 + 7;
ll n;
ll m;
ll dp[N], ans[N];
int main() {
	cin >> n >> m;
	ll sum = 0;
	dp[1] = 1;
	for (ll i = 1; i <= n; i++) {
		ans[i] += ans[i - 1];
		ans[i] %= m;
		dp[i] += sum + ans[i];
		dp[i] %= m;
		for (ll j = 2; j * i <= n; j++) { // 枚举倍数
			ans[i * j] += dp[i];		  // 在i*j处加上f(i)的贡献
			ans[i * j] %= m;			  // 分块转移
			if (i * j + j <= n) {
				ans[i * j + j] += m - dp[i]; // 在i*j+j处减去f(i)的贡献
				ans[i * j + j] %= m;
			}
		}
		sum = (sum + dp[i]) % m;
	}
	cout << dp[n] << endl;
	return 0;
}
