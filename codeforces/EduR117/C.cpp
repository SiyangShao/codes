#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k, x;
bool check(ll mid) {
	ll sum = 0;
	if (mid > k)
		sum = (1 + k) * k / 2 + ((k - 1) + 2 * k - mid) * (mid - k) / 2;
	else
		sum = (1 + mid) * mid / 2;
	if (sum < x)
		return 1;
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll T;
	cin >> T;
	while (T--) {
		cin >> k >> x;
		ll l = 0, r = 2 * k - 1;
		while (l < r) {
			ll mid = (l + r) / 2;
			if (check(mid))
				l = mid + 1;
			else
				r = mid;
		}
		cout << l << "\n";
	}

	return 0;
}