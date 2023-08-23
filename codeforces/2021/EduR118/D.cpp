#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
int main() {
	ll t, n, a;
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll> dp1(n + 2), dp2(n + 2);
		// dp1: MEX is larger then max
		// dp2: MEX is smaller then max
		dp1[0] = 1;
		for (int i = 0; i < n; ++i) {
			cin >> a;
			dp1[a + 1] = (dp1[a + 1] + dp1[a + 1] + dp1[a]) % mod;
			dp2[a + 1] = (dp2[a + 1] + dp2[a + 1]) % mod;
			if (a > 0) {
				dp2[a - 1] = (dp2[a - 1] + dp2[a - 1] + dp1[a - 1]) % mod;
			}
		}
		ll ans = -1;
		for (int i = 0; i <= n; ++i) {
			ans = (ans + dp1[i] + dp2[i]) % mod;
		}
		cout << ans << "\n";
	}
}