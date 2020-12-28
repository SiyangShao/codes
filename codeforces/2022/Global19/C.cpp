#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	cin >> n;
	vector<ll> a(n - 2);
	ll num = 0;
	ll begin, end;
	ll one = 0, three = 0, tt = 0, two = 0;
	cin >> begin;
	for (auto &i : a) {
		cin >> i;
		num += (i + 1) / 2;
		if (i % 2 == 0) {
			two++;
		} else if (i == 1) {
			one++;
		} else {
			three++;
		}
	}
	cin >> end;

	if (three == 1 && one == 0 && two == 0) {
		cout << "-1\n";
	} else if (two == 0 && three == 0) {
		cout << "-1\n";
	} else {
		cout << num << "\n";
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