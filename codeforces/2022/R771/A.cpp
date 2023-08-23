#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto &i : a)
		cin >> i;
	ll cnt = 0, search = 0, begin = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] != i + 1) {
			search = i + 1;
			break;
		} else {
			begin = i + 1;
			cnt = i + 1;
		}
	}
	// cout << begin << " " << cnt << " " << search << "::::";
	for (int i = begin; i < n; ++i) {
		if (a[i] == search) {
			cnt = i;
			break;
		}
	}
	for (int i = 0; i < begin; ++i) {
		cout << a[i] << " ";
	}
	if (begin != n) {
		for (int i = cnt; i >= begin; --i) {
			cout << a[i] << " ";
		}
		for (int i = cnt + 1; i < n; ++i) {
			cout << a[i] << " ";
		}
	}
	cout << "\n";
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