#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

void solve() {
	string s;
	cin >> s;
	int f = 0;
	for (auto i : s) {
		if (i == 'N') {
			f++;
		}
	}
	if (f == 1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}