#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300010;
int n;
ll m;
ll dp[N];
int main() {
	cin >> n >> m;
	ll sum = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		sum += dp[i - 1];
		sum %= m;
		dp[i] += sum;
		for (int l = 2, r; l <= i; l = r + 1) {
			r = i / (i / l);
			dp[i] += ((r - l + 1) * dp[i / l]);
			dp[i] %= m;
		} // 整除分块
	}
	cout << dp[n] << endl;
	return 0;
}
