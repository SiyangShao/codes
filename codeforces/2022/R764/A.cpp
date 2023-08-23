#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
	int n, l, r;
	l = 0x3f3f3f3f, r = 0;
	cin >> n;
	for (int i = 1, tmp; i <= n; ++i) {
		cin >> tmp;
		l = min(l, tmp);
		r = max(r, tmp);
	}
	cout << r - l << "\n";
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