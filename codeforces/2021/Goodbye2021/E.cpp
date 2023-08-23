#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
int n;
string s, t;
int flag1, flag2;
void solve() {
	cin >> n >> s >> t;
	flag1 = -1, flag2 = -1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) {
			continue;
		}
		if (s[i] > t[i]) {
			flag1 = i;
			break;
		}
		if (s[i] < t[i]) {
			flag2 = i;
			break;
		}
	}
	if (flag2 != -1) {
		cout << "0\n";
		return;
	}
	int flag3 = -1;
	for (int j = flag1 + 1; j < n; ++j) {
		if (s[j] < t[flag1]) {
			flag2 = j;
			break;
		}
		if (flag3 == -1 && s[j] == t[flag1]) {
			flag3 = j;
		}
	}
	if (flag3 == -1 && flag2 == -1) {
		cout << "-1\n";
		return;
	}
	if (flag2 != -1) {
		cout << flag2 - flag1 << "\n";
		return;
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