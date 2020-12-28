#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn = 2e5 + 7;

vector<int> a;
void init() {
	int i = 1;
	a.emplace_back(i);
	while (i <= maxn*2) {
		i *= 2;
		a.emplace_back(i);
	}
}
void solve() {
	ll l, r;
	cin >> l >> r;
	ll L = a.size(), R = a.size();
	for (int i = 0; i < a.size(); ++i) {
		if (l < a[i]) {
			L = i;
			break;
		}
	}
	for (int i = 0; i < a.size(); ++i) {
		if (r < a[i]) {
			R = i;
			break;
		}
	}
	// cout << L << " " << R << "\n";
	if (L == R) {
		cout << "0\n";
		return;
	}
	ll minium = 2e5 + 7;
	r++;
	for (int i = 1; i <= R; ++i) {
		ll less, more;
		less = a[i - 1] * ll(l / a[i]) +
			   (l % a[i] < a[i - 1] ? l % a[i] : a[i - 1]);
		more = a[i - 1] * ll(r / a[i]) +
			   (r % a[i] < a[i - 1] ? r % a[i] : a[i - 1]);
		// cout << i << " " << less << " " << more << "\n";
		minium = min(minium, more - less);
	}
	cout << minium << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	init();
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
}