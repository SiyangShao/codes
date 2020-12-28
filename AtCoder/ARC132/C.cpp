#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
constexpr int mod = 998244353;
int n, d, ans;
vector<int> a;
vector<vector<int>> dp;
void solve() {
	cin >> n >> d;
	a.resize(n);
	for (auto &i : a) {
		cin >> i;
		--i;
	}
	dp.resize(n + 1, vector<int>(1 << d + d + 1));
	dp[0][(1 << d + 1) - 1] = 1;
	for (int i = 0; i < n; ++i) {
		for (int set = 1; set < (1 << d + d + 1); set += 2) {
			const int newSet = set >> 1;
			for (int j = 0; j < d + d + 1; ++j) {
				if (a[i] >= 0 && a[i] != i + j - d) {
					continue;
				}
				if (~newSet >> j & 1) {
					dp[i + 1][newSet | 1 << j] =
						(dp[i + 1][newSet | 1 << j] + dp[i][set]) % mod;
				}
			}
		}
	}
	cout << dp[n][(1 << (d + 1)) - 1];
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}