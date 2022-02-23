#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (auto &i : a) {
			cin >> i;
		}
		sort(a.begin(), a.end());
		auto mi = *a.begin();
		for (int i = 1; i <= n / 2; ++i) {
			cout << a[i] << " " << mi << "\n";
		}
	}
}