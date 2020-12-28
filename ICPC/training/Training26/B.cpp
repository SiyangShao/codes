#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;

void solve() {
	string s;
	cin >> s;
	string s1 = s;
	for (auto i : s) {
		switch (i) {
		case 'A':
			break;
		case 'H':
			break;
		case 'I':
			break;
		case 'M':
			break;
		case 'O':
			break;
		case 'T':
			break;
		case 'U':
			break;
		case 'V':
			break;
		case 'W':
			break;
		case 'X':
			break;
		case 'Y':
			break;
		default:
			cout << "NO";
			return;
		}
	}
	reverse(s1.begin(), s1.end());
	if (s == s1) {
		cout << "YES";
	} else {
		cout << "NO";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_--) {
		solve();
	}
}