#include <bits/stdc++.h>
using namespace std;
void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	int num = n / m;
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	int rot = (n % m) * ((n + m - 1) / m);
	for (int round = 0; round < k; ++round) {
		int index = 0;
		for (int table = 0; table < m; ++table) {
			if (table < n % m) {
				cout << num + 1;
				for (int j = 0; j < num + 1; ++j) {
					cout << " " << p[index++] + 1;
				}
			} else {
				cout << num;
				for (int j = 0; j < num; ++j) {
					cout << " " << p[index++] + 1;
				}
			}
			cout << "\n";
		}
		rotate(p.begin(), p.begin() + rot, p.end());
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
		cout << "\n";
	}
}