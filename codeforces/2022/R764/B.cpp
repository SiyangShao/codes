#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	ll a, b, c;
	cin >> a >> b >> c;
	if (((b * 2 - c) % a == 0 && b * 2 - c > 0) ||
		((b * 2 - a) % c == 0 && b * 2 - a > 0) ||
		((a + c) % (2 * b) == 0 && a + c >= 2 * b)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
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