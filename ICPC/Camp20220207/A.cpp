#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
typedef vector<ll> vl;
#define eb emplace_back
#define all0(x) begin(x), end(x)
#define all1(x) begin(x) + 1, end(x)
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define ROF(i, a, b) for (ll i = (a); i >= (b); i--)
#define chkmax(x, a) x = max(x, a)
#define chkmin(x, a) x = min(x, a)

ll a[1048579];
ll b[1048579];
ll dp[1048579][22][2]; // dp[i][k][bool]
ll n;
void check() {
	for (int i = 0; i < (1 << n); ++i) {
		ll sum = 0;
		for (int j = 0; j < (1 << n); ++j) {
			if (__builtin_popcount(i & j) % 2 == 1) {
				sum += a[j];
			}
		}
		cout << sum << " ";
	}
}
void solve() {
	cin >> n;
	FOR(i, 0, (1 << n) - 1) cin >> a[i];

	FOR(i, 0, (1 << n) - 1) dp[i][0][0] += a[i];
	FOR(k, 1, n) FOR(i, 0, (1 << n) - 1) FOR(isOdd, 0, 1) {
		int tb = 1 << (k - 1);
		if (!(i & tb)) { // kth bit off
			dp[i][k][isOdd] =
				dp[i][k - 1][isOdd] +
				dp[i ^ tb][k - 1][isOdd]; // both can, no restriction
		} else {
			dp[i][k][isOdd] =
				dp[i][k - 1][!isOdd] + dp[i ^ tb][k - 1][isOdd]; // only..
		}
	}
	FOR(i, 0, (1 << n) - 1) cout << dp[i][n][true] << " ";
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll T = 1;
	// cin >> T;
	while (T--)
		solve();
	check();
	return 0;
}
