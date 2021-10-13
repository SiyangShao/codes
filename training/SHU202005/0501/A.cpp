#include <bits/stdc++.h>
using namespace std;
#define int long long
int q, l, r, v;
int n, a[500010], suma, sumb;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (i % 2 == 1) {
			suma += a[i];
		} else {
			sumb += a[i];
		}
	}
	cin >> q;
	while (q--) {
		cin >> l >> r >> v;
		if (l % 2 == r % 2) {
			if (l % 2 == 1) {
				suma += v;
			} else {
				sumb += v;
			}
		}
		if (n % 2 == 1) {
			cout << suma - sumb<<"\n";
		} else {
			cout << sumb - suma<<"\n";
		}
	}
}