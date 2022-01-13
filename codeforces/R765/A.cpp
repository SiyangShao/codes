#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll n, l;
	cin >> n >> l;
	vector<ll> x(n), jud(l);
	for (auto &i : x) {
		cin >> i;
		auto tmp = i;
		for (int j = 0; j < l; ++j) {
			if (tmp % 2 == 1) {
				jud[j]++;
			}
			tmp /= 2;
		}
	}
	ll ans = 0, add = 1;
	for (ll j = 0; j < l; ++j) {
		// cout << jud[j] << " ";
		if (n % 2 == 1) {
			if (jud[j] >= n / 2 + 1) {
				ans += add;
			}
		} else {
			if (jud[j] >= n / 2) {
				ans += add;
			}
		}
		add *= 2;
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