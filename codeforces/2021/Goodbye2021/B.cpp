#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
void solve() {
	int n;
	string s;
	cin >> n >> s;
	vector<int> ans;
	if (n == 1) {
		cout << s << s << "\n";
		return;
	}
	int flag = n - 1;
	if (s[0] == s[1]) {
		cout << s[0] << s[0] << "\n";
		return;
	}
	for (int i = 0; i < n - 1; ++i) {
		if (s[i] < s[i + 1]) {
			flag = i;
			break;
		}
	}
	for (int i = 0; i <= flag; ++i) {
		cout << s[i];
	}
	for (int i = flag; i >= 0; --i) {
		cout << s[i];
	}
	cout << "\n";
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