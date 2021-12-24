#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void solve() {
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	if (s1 == s2) {
		cout << 0 << "\n";
		return;
	}
	int Light_l = 0, Light_r = 0;
	for (int i = 0; i < n; ++i) {
		if (s1[i] == '1') {
			Light_l++;
		}
		if (s2[i] == '1') {
			Light_r++;
		}
	}
	if (Light_l == 0 || (Light_l != Light_r && Light_l + Light_r != n + 1)) {
		cout << -1 << "\n";
		return;
	}
	int differ = 0, same = 0;
	for (int i = 0; i < n; ++i) {
		if (s1[i] != s2[i]) {
			differ++;
		} else {
			same++;
		}
	}
	if (n - Light_l + 1 != Light_r) {
		cout << differ << "\n";
		return;
	}
	int D = differ;
	swap(differ, same);
	differ--;
	same++;
	// cout << differ << " " << same << "\n";
	if (differ % 2 == 0) {
		if (Light_l == Light_r) {
			cout << min(differ + 1, D) << "\n";
		} else {
			cout << differ + 1 << "\n";
		}
	} else {
		if (Light_l == Light_r)
			cout << D << "\n";
		else
			cout << -1 << "\n";
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	int _;
	cin >> _;
	while (_--) {
		solve();
	}
}