#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
inline void solve() {
	ll a, s;
	cin >> a >> s;
	if (s < a) {
		cout << "-1\n";
	} else {
		ll b = 0;
		ll cnt = 1;
		while (s && a) {
			if (s % 10 >= a % 10) {
				b += (s % 10 - a % 10) * cnt;
				s /= 10;
				a /= 10;
				cnt *= 10;
			} else {
				ll tmp = s % 100;
				if (tmp < 10 || tmp >= 20) {
					cout << "-1\n";
					return;
				}
				b += (tmp - a % 10) * cnt;
				s /= 100;
				a /= 10;
				cnt *= 10;
			}
		}
		if (a) {
			cout << "-1\n";
			return;
		}
		if (s) {
			b += cnt * s;
		}
		cout << b << "\n";
	}
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