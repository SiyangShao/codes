#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
	int n;
	cin >> n;
	vector<ll> a(n), b(n);
	for (auto &i : a) {
		cin >> i;
	}
	for (auto &i : b) {
		cin >> i;
	}
	ll A = 0, B = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
		}
		A = max(A, a[i]);
		B = max(B, b[i]);
	}
	cout << A * B << "\n";
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