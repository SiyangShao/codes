#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, k;
	cin >> n >> k;
	vector<pair<int, int>> a(n);
	for (auto &i : a) {
		cin >> i.first;
	}
	for (auto &i : a) {
		cin >> i.second;
	}
	sort(a.begin(), a.end(), [](auto x, auto y) { return x.first < y.first; });
	for (const auto &[x, y] : a) {
		if (k >= x) {
			k += y;
		}
	}
	cout << k << "\n";
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