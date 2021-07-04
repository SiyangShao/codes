#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
	int t = 1;
	cin >> t;
	while (t--) {
		ll n, x;
		ll sum1 = 0, sum2 = 0;
		ll mn1 = 1e16, mn2 = 1e16;
		ll ans = 1e16;
		ll c1 = 0, c2 = 0;

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x;
			if (i % 2 == 0) {
				c1++;
				sum1 += x;
				mn1 = min(mn1, x);
			} else {
				c2++;
				sum2 += x;
				mn2 = min(mn2, x);
			}

			if (i >= 1) {
				ans = min(ans, (sum1 + sum2 - mn1 - mn2) + mn1 * (n - c1 + 1) +
								   mn2 * (n - c2 + 1));
			}
		}
		cout << ans << endl;
	}
	return 0;
}
