#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	cout << s << "\n";
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