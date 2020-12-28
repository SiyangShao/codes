#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n;
	string s;
	cin >> n >> s;
	if (n >= 3) {
		cout << "NO\n";
	} else {
		if (n == 2) {
			if (s[0] == s[1]) {
				cout << "NO\n";
			} else
				cout << "YES\n";
		} else {
			cout << "YES\n";
		}
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