#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e5 + 7;
const ll A = 2e7 + 7;
ll a[N], n, ma;
ll dp[A], pre[A], coun[A];
ll vis[A];
vector<ll> pri;
void init() {
	for (int i = 2; i <= ma; ++i) {
		if (!vis[i]) {
			pri.push_back(i);
		}
		for (auto j : pri) {
			if (1ll * i * j > ma)
				break;
			vis[i * j] = 1;
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		coun[a[i]]++;
		ma = ma > a[i] ? ma : a[i];
	}
	init();
	for (ll i = 1; i <= ma; ++i) {
		for (ll j = i; j <= ma; j += i) {
			pre[i] += coun[j];
		}
	}
	for (ll i = ma; i >= 1; --i) {
		dp[i] = i * pre[i];
		for (auto j : pri) {
			if (i * j > ma)
				break;
			dp[i] = max(dp[i], dp[i * j] + (pre[i] - pre[i * j]) * i);
		}
	}
	cout << dp[1] << "\n";
}