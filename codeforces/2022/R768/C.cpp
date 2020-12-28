#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void judge(ll k) {
	if (k == 3) {
		cout << "-1\n";
		return;
	}
	cout << k << " " << k - 1 << "\n";;
	cout << k - 2 << " " << 1 << "\n";
	cout << 0 << " " << 2 << "\n";
	for (int i = 3, j = k - 3; i < j; ++i, --j) {
		cout << i << " " << j << "\n";
	}
}
void solve() {
	ll n, k;
	cin >> n >> k;
	if (k == n - 1) {
		judge(k);
		return;
	}
	cout << k << " " << n - 1 << "\n";
	if (k)
		cout << 0 << " " << n - 1 - k << "\n";
	for (int i = 0; i < n / 2; ++i) {
		if (i == 0 || i == k || i == n - 1 - k)
			continue;
		cout << i << " " << n - 1 - i << "\n";
	}
	// cout << "\n";
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