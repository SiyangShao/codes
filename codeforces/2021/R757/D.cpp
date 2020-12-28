#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;
const ll A = 5e6 + 7;
ll a[N], n, ma;
ll dp[A], pre[A], coun[A];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		coun[a[i]]++;
		ma = ma > a[i] ? ma : a[i];
	}
	for (ll i = 1; i <= ma; ++i) {
		for (ll j = i; j <= ma; j += i) {
			pre[i] += coun[j];
		}
	}
	for (ll i = ma; i >= 1; --i) {
		dp[i] = i * pre[i];
		for (ll j = i + i; j <= ma; j += i) {
			dp[i] = max(dp[i], dp[j] + (pre[i] - pre[j]) * i);
		}
	}
	cout << dp[1] << "\n";
}