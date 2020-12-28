#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double eps = 1e-8;
inline void solve() {
	ll n;
	cin >> n;
	ll a = pow(n, 1.0 / 2);
	ll b = pow(n, 1.0 / 3);
	ll c = pow(n, 1.0 / 6);
	if ((a + 1) * (a + 1) <= n) {
		a++;
	}
	if ((b + 1) * (b + 1) * (b + 1) <= n) {
		b++;
	}
	if ((c + 1) * (c + 1) * (c + 1) * (c + 1) * (c + 1) * (c + 1) <= n) {
		c++;
	}
	cout << a + b - c << "\n";
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