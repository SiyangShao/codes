#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int judge() {
	int k;
	cin >> k;
	vector<int> s(k);
	for (auto &i : s) {
		cin >> i;
	}
	sort(s.begin(), s.end());
	return (*(s.end() - 1) - *s.begin());
}
void solve() {
	int w, h;
	cin >> w >> h;
	int a = judge();
	int b = judge();
	int c = judge();
	int d = judge();
	a *= h, b *= h;
	c *= w, d *= w;
	cout << max(max(a, b), max(c, d)) << "\n";
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int _ = 1;
	cin >> _;
	while (_--) {
		solve();
	}
}