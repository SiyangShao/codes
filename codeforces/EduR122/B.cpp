#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	string s;
	cin >> s;
	ll ans = 0;
	ll zero = 0, one = 0;
	for (auto i : s) {
		if (i == '1')
			one++;
		else
			zero++;
		if (one != zero)
			ans = max(ans, min(zero, one));
	}
	cout << ans << "\n";
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