#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int H, W, K;
	cin >> H >> W >> K;
	vector<ll> dp(4);
	dp[0] = 1;
	vector<ll> nx(4); // dp -> nx
	while (K--) {
		nx[0] = (dp[1] * (W - 1) % mod + dp[2] * (H - 1) % mod) %
				mod; // Point (x1,y1)
		nx[1] = (dp[0] + dp[1] * (W - 2) % mod + dp[3] * (H - 1) % mod) %
				mod; // Point (x,y1)
		nx[2] = (dp[0] + dp[2] * (H - 2) % mod + dp[3] * (W - 1) % mod) %
				mod; // Point (x1,y)
		nx[3] = (dp[1] + dp[2] + dp[3] * (H + W - 4) % mod) % mod; // else
		dp = nx;
	}

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	ll ans = x1 == x2 ? (y1 == y2 ? dp[0] : dp[1]) : (y1 == y2 ? dp[2] : dp[3]);
	cout << ans % mod << endl;
}
