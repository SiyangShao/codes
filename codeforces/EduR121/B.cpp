#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	string s;
	cin >> s;
	int N = s.length();
	int flag = -1;
	int sum = 0;
	for (int i = N - 2; i >= 0; --i) {
		auto x = s[i] - '0', y = s[i + 1] - '0';
		if (x + y >= 10) {
			flag = i;
			sum = x + y;
			break;
		}
	}
	if (flag != -1) {
		for (int i = 0; i < flag; ++i) {
			cout << s[i];
		}
		cout << sum;
		for (int i = flag + 2; i < N; ++i) {
			cout << s[i];
		}
		cout << "\n";
	} else {
		cout << (s[0] - '0' + s[1] - '0');
		for (int i = 2; i < N; ++i) {
			cout << s[i];
		}
		cout << "\n";
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}