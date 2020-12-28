#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n);
	vector<ll> odd, even;
	for (auto &i : a) {
		cin >> i;
		if (i % 2 == 1) {
			odd.emplace_back(i);
		} else {
			even.emplace_back(i);
		}
	}
	if (is_sorted(odd.begin(), odd.end()) &&
		is_sorted(even.begin(), even.end())) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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