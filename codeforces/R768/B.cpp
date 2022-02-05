#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	for (int i = n - 1; i >= 0; --i) {
		cin >> a[i];
	}
	ll len = 2, pre = 1;
	ll num = a[0];
	ll ans = 0;
	while (len <= n * 2) {
		for (ll i = pre; i < min(len, n); ++i) {
			if (a[i] != num) {
				ans++;
				break;
			}
		}
		pre = len;
		while (pre < n && a[pre] == num) {
			pre++;
		}
		len = pre * 2;
	}
	cout << ans << "\n";
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