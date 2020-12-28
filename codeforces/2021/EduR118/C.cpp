#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, h;
ll a[110];
bool judge(ll x) {
	ll harm = x;
	for (int i = 1; i < n; ++i) {
		harm += min(a[i + 1] - a[i], x);
	}
	return harm >= h;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> h;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		ll l = 1, r = h, mid, ans = h;
		while (l <= r) {
			mid = (l + r) / 2;
			if (judge(mid)) {
				r = mid - 1;
				ans = min(ans, mid);
			} else {
				l = mid + 1;
			}
		}
		cout << ans << "\n";
	}
}