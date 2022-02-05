#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr ll N = 1000;
ll d[N], a[N], dp[N][N];
void solve() {
	ll n, l, k;
	cin >> n >> l >> k;
	for (int i = 1; i <= n; i++)
		cin >> d[i];
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	d[++n] = l;
	memset(dp, 0x3f, sizeof(dp));
	dp[1][k] = 0;
	for (int i = 2; i <= n; i++)
		for (int j = 1; j < i; j++)
			for (int p = 0; p <= k; p++)
				if (p + i - j - 1 <= k)
					dp[i][p] = min(dp[i][p], dp[j][p + (i - j - 1)] +
												 a[j] * (d[i] - d[j]));

	cout << *min_element(&dp[n][0], &dp[n][k + 1]) << '\n';
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}