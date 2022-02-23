#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, cnt = 0;
	cin >> n;
	vector<int> a(n);
	int maxi = 0;
	for (auto &i : a) {
		cin >> i;
		maxi = i > maxi ? i : maxi;
	}
	for (auto i = a.end() - 1; i >= a.begin(); i--) {
		if (*i == maxi) {
			cout << cnt << "\n";
			return;
		}
		for (auto j = i - 1; j >= a.begin(); j--) {
			if (*j > *i) {
				i = j + 1;
				cnt++;
				break;
			}
		}
	}
	cout << cnt << "\n";
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
}