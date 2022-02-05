#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n, k, sum = 0;
	cin >> n >> k;
	vector<ll> a(n);
	for (auto &i : a) {
		cin >> i;
		sum += i;
	}
	if (sum <= k) {
		cout << "0\n";
		return;
	} else if (n == 1) {
		cout << sum - k << "\n";
		return;
	}
	// cout << sum << "\n";
	sum -= k;
	sort(a.begin(), a.end());
	vector<ll> dp(n);
	ll num = 0x3f3f3f3f3f3f3f3f;
	ll flag = 0;
	for (int i = n - 2; i >= 0; --i) {
		dp[i] = a[i + 1] - a[0];
		dp[i] += dp[i + 1];
		if (dp[i] >= sum) {
			num = min(num, n - i - 1);
			flag = i;
			// cout << dp[i] << " " << num << "\n";
			break;
		}
	}
	// cout << flag << "\n";
	for (int i = n - 1; i >= 0; --i) {
		if (i < flag)
			break;
		if (sum < dp[i]) {
			break;
		}
		ll x = ceil(double(sum - dp[i]) / double(n - i));
		// cout << dp[i] << " " << x << "\n";
		num = min(num, x + n - i - 1);
	}
	cout << num << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}