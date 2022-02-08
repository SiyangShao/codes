#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline void solve() {
	// S
	// S + R, R + S
	// S + R + S + R, R + S + R + S
	int n, k;
	string s;
	cin >> n >> k >> s;
	if (k == 0) {
		cout << "1\n";
		return;
	}
	string tmp = s;
	reverse(tmp.begin(), tmp.end());
	if (tmp == s) {
		cout << "1\n";
	} else {
		cout << "2\n";
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