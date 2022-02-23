#include <bits/stdc++.h>
using namespace std;
bool judge(int x) {
	for (int i = 2; i <= sqrt(x); ++i) {
		if (x % i == 0)
			return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1, n;
	cin >> _;
	while (_--) {
		cin >> n;
		vector<pair<int, int>> a(n);
		int j = 1, ans = 0, tmp;
		for (auto &i : a) {
			cin >> tmp;
			i.first = tmp;
			i.second = j;
			ans += i.first;
			j++;
		}
		if (!judge(ans)) {
			cout << n << "\n";
			for (int i = 1; i <= n; ++i) {
				cout << i << " ";
			}
			cout << "\n";
		} else {
			ans = 1;
			for (auto i : a) {
				if (i.first % 2 == 1) {
					ans = i.second;
					break;
				}
			}
			cout << n - 1 << "\n";
			for (int i = 1; i <= n; ++i) {
				if (i != ans) {
					cout << i << " ";
				}
			}
			cout << "\n";
		}
	}
}