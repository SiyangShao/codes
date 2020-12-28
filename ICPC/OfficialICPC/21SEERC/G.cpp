#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int n;
	ll ans = 0;
	cin >> n;
	vector<pair<ll, ll>> x(n * 2);
	for (auto &[a, b] : x) {
		cin >> a >> b;
		ans += abs(a - b);
	}
	sort(x.begin(), x.end(), [](auto x, auto y) {
		return abs(x.first + x.second) > abs(y.first + y.second);
	});
	ll p = 0, r = n * 2 - 1;
	// cout << endl;
	// for (int i = 0; i < n * 2; ++i) {
	// 	cout << x[i].first << " " << x[i].second << endl;
	// }
	while (p < r) {
		ans += abs(x[p].first + x[p].second) - abs(x[r].first + x[r].second);
		p++;
		r--;
	}
	ans /= 2;
	cout << ans;
}